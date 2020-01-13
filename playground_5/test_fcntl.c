#include <fcntl.h>

#include "../libtlpi/tlpi_hdr.h"
#include "../libft/libft.h"

int		main(int argc, char *argv[]) {

	int open_flags  = O_CREAT | O_WRONLY ;
	int file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | 
					S_IROTH | S_IWOTH;

	char *line = NULL;

	int fd = open(argv[1], open_flags, file_perms);

	ft_putendl_fd("TEST", fd);

	int flags = fcntl(fd, F_GETFL);
	if (flags == -1)    
		errExit("fcntl");
	flags |= O_APPEND;
	if (fcntl(fd, F_SETFL, flags) == -1)    
		errExit("fcntl");

	ft_putendl_fd("TEST", fd);

	close(fd); 
	return (0);
}