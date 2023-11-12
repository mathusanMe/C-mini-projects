# Tar-utilities

The objective of this practical work is to program a tool that can retrieve certain information from `tar` archives. 

It's important to remember that `tar` is an archiving tool, which allows for the following uses, for example:

```bash
tar tvf test.tar                            # lists the files contained in test.tar
tar xf test.tar                             # extracts the files present in test.tar
tar cf test.tar file1 ... fileN             # creates an archive named test.tar
```

Note: By default, a `tar` archive is not compressed, but it can be compressed using a tool like `gzip` to obtain compressed archives `*.tar.gz`, often also named `*.tgz`. The tar tool can directly do this, see for example `tar czf`. In this practical work, we will only work with uncompressed `tar` archives.

## TAR Archive Format Overview

TAR (Tape Archive) is a popular file format for storing a sequence of files and directories. Here's a brief overview of some key fields in the TAR format, based on the POSIX header structure:

### `name`
- **Type**: `char[100]`
- **Offset**: 0
- **Description**: 
  - Stores the name of the file or directory.
  - Limited to 100 characters.

### `mode`
- **Type**: `char[8]`
- **Offset**: 100
- **Description**: 
  - Represents file mode and permissions.
  - Stored in an 8-character array.

### `size`
- **Type**: `char[12]`
- **Offset**: 124
- **Description**: 
  - Contains the size of the file in bytes.
  - Represented as an ASCII string.

### `chksum`
- **Type**: `char[8]`
- **Offset**: 148
- **Description**: 
  - Used for error checking.
  - Stores the checksum of the header.

### `typeflag`
- **Type**: `char`
- **Offset**: 156
- **Description**: 
  - Indicates the type of file.
  - Common values include '0' or '\0' for regular files, '1' for hard links, '2' for symbolic links, and others for directories, character devices, block devices, etc.

## Block Size
- The header is stored in blocks of 512 bytes, as defined by `BLOCKSIZE`.

## Instructions

### How to compile

After cloning the repository, run the following commands in the `tar-utilities` folder:
```bash
make tarexamples    # prepares the test files
make all
```

### How to run commands

#### Example 1 : List the files in a tar archive

After compiling, run the following commands in the `tar-utilities` folder:
```bash
./tarutilities l /tmp/tweety.tar
```
`l` is the command to list the files in the archive.

## Commands
``` bash
./tarutilities l <archive>  # lists the files in the archive
```