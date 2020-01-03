#include "../libtlpi/tlpi_hdr.h"
#include "../libft/libft.h"
#include <ctype.h>
#include <fcntl.h>

int		main(int argc, char *argv[])
{
	int opt;
	int open_flags;
	int file_perms;
	int fd;
	int opt_check;

	opt_check = 0;
	open_flags = O_CREAT | O_WRONLY | O_TRUNC ;
	file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | 
				S_IROTH | S_IWOTH;
	
	while ((opt = getopt(argc , argv, "a")) != -1)
	{
		if (opt == 'a')
			opt_check = 1;
		else 
			opt_check = 0;
	}
	
	if (opt_check)
		open_flags = open_flags ^ O_TRUNC; 
	fd = open(argv[optind], open_flags, file_perms);

	close(fd); 
	exit(EXIT_SUCCESS);
}