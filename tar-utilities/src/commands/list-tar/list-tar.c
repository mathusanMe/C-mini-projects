#include "list-tar.h"

int is_valid_filename(char *filename)
{
    if (strlen(filename) == 0)
    {
        return 0;
    }

    if (filename[0] == '/')
    {
        return 0;
    }

    for (int i = 1; i < strlen(filename); i++)
    {
        if (!isalnum(filename[i]))
        {
            return 0;
        }
    }

    return 1;
}

int listar(char *tarname)
{
    int fd, ret = 0;
    unsigned int filesize, filemode, nblocks;
    struct posix_header *phd = &hd;

    /* Open tar file */
    fd = open(tarname, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening tar file");
        exit(1);
    }

    /* Main Loop */
    while (1)
    {
        /* Read header; Verify if read was successful */
        int n;
        n = read(fd, phd, BLOCKSIZE);

        if (n != BLOCKSIZE)
        {
            perror("Error reading tar header");
            ret = 1;
            break;
        }

        /* Check if we reached the end of the archive, particularly if name == "" */
        if (phd->name[0] == '\0')
        {
            break;
        }

        /* Checksum Verification */
        if (!check_checksum(phd))
        {
            fprintf(stderr, "Checksum erronée : %s\n", phd->chksum);
            ret = 1;
            break;
        }

        /* Get file mode, size and occupied number of blocks */
        sscanf(phd->mode, "%o", &filemode);
        sscanf(phd->size, "%o", &filesize);
        nblocks = (filesize + BLOCKSIZE - 1) >> BLOCKBITS; // Same as : (filesize + BLOCKSIZE - 1) / BLOCKSIZE

        /* Print file mode in octal, file size in decimal and number of blocks in decimal, file name */
        if (is_valid_filename(phd->name))
        {
            printf("%o\t%d\t%d\t%s\n", filemode, filesize, nblocks, phd->name);
        }
        else
        {
            fprintf(stderr, "Invalid file name : %s\n", phd->name);
            ret = 1;
            break;
        }

        /* Skip file content */
        lseek(fd, nblocks * BLOCKSIZE, SEEK_CUR);
    }

    close(fd);

    return ret;
}