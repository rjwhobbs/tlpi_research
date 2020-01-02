#include "../libtlpi/tlpi_hdr.h"
#include "../libft/libft.h"
#include <ctype.h>
#include <fcntl.h>

int		main(int argc, char *argv[])
{
	int opt;
	int openFlags;
	int filePerms;
	int fd;

	openFlags = O_CREAT | O_WRONLY | O_TRUNC ;
	filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | 
				S_IROTH | S_IWOTH;
	
	while ((opt = getopt(argc , argv, "a")) != -1)
	{
		// Needs error handling
		// I don't like how this loops with a string with multiple flags
		// perhaps I should make a toggle in here
		openFlags = openFlags ^ O_TRUNC; 
	}

	fd = open(argv[1], openFlags, filePerms);

	close(fd); 
	exit(EXIT_SUCCESS);
}