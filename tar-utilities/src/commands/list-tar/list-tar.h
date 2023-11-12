#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include "../../utils/tarutils.h"

struct posix_header hd;

/* Check if file name is valid :
 * - not empty
 * - does not contain '/'
 * - does contain only alphanumeric characters other than at the beginning
 */
int is_valid_filename(char *filename);

/* List the content of the tar file tarname
 * Return 0 if success, -1 otherwise
 */
int listar(char *tarname);
