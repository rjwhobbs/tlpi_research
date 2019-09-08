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

	openFlags = O_CREAT | O_RDONLY | O_TRUNC;
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
	outputFd = open(av[2], openFlags, filePerms); //perms 0666
	if (outputFd == -1)
		errExit("opening file %s", av[2]);

	/* Transfer data until we encounter end of input or an error */

	while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0)
		if ((write(outputFd, buf, BUF_SIZE) != numRead))
			fatal("couldn't write whole buffer");
	
	if (numRead == -1)
		errExit("read");
	
	if (close(inputFd) == -1)
		errExit("close input");
	if (close(outputFd) == -1)
		errExit("close output");

	exit(EXIT_SUCCESS);
}