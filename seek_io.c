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
	
	for (ap = 2; ap < ac; ap++)
	{
		switch (av[ap][0])
		{
		case 'r': // Display bytes at current offset as text.
		case 'R': // Display bytes at current offset in hex.
			len = getLong(&av[ap][1], GN_ANY_BASE, av[ap]);
			buf = (char*)malloc(sizeof(char) * len);
			if(!buf)
				errExit("malloc");
			numRead = read(fd, buf, len);
			if (numRead == -1)
				errExit("read");
			if (!numRead)
				printf("%s: end-of-file\n", av[ap]);
			else
			{
				printf("%s: ", av[ap]);
				for (j = 0; j < numRead; j++)
				{
					if (av[ap][0] == 'r')
						printf("%c", isprint((unsigned char)buf[j]) ? buf[j]: '?');
					else
						printf("%02x", (unsigned int)buf[j]);
				}
				printf("\n");
			}
			free(buf);
			break;
		case 'w': // Write string at current offset.
			numWritten = write(fd, &av[ap][1], strlen(&av[ap][1]));
			if (numWritten == -1)
				errExit("write");
			printf("%s: wrote %ld bytes\n", av[ap], (long)numWritten);
			break;
		case 's': // Change file offset.
			offset = getLong(&av[ap][1], GN_ANY_BASE, av[ap]);
			if (lseek(fd, offset, SEEK_SET) == -1)
				errExit("lseek");

		default:
			break;
		}
		//missing code
	}

}