#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "tlpi_hdr.h"

int
main	(int ac, char *av[])
{
	char	*buf;
	size_t	len;
	ssize_t	numRead;
	ssize_t	numWritten;
	off_t	offset;
	int		fd;
	int		ap;
	int		j;

	if (ac < 3 || strcmp(av[1], "--help") == 0)
		usageErr("%s file {r<length>|R<length>|w<string>|s<offset>}...\n", av[0]);
	fd = open(av[1], O_RDWR | O_CREAT,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
					S_IROTH | S_IWOTH);
	if (fd == -1)
		errExit("open"); 

}