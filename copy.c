#include "../libft/libft.h"
#include "tlpi_hdr.h"
#include <fcntl.h>

#ifndef BUF_SIZE 			/* Allow "cc -D" to override definition */
# define BUF_SIZE 1024
#endif

int		main(int ac, char *av[])
{
	int 		inputFd;
	int			outputFd;
	int			openFlags;
	mode_t 		filePerms;
	ssize_t		numRead;
	char 		buf[BUF_SIZE];

	if (ac != 3 || ft_strcmp(av[1], "--help") == 0)
		usageErr("%s old-file new-file\n", av[0]);
	inputFd = open(av[1], O_RDONLY);
	if (inputFd == -1)
		errExit("opening file %s", av[1]);
	return (0);
}