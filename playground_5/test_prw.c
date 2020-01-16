#include <fcntl.h>

#include "../libft/libft.h"
#include "../libtlpi/tlpi_hdr.h"

int		main(int argc, char *argv[]) {
	int open_flags = O_CREAT | O_EXCL | O_RDWR ;
	int file_perms = S_IRUSR | S_IWUSR ;

	int fd = open(argv[1], open_flags, file_perms);

	dprintf(fd, "XXXXXXXXXXXX");
	pwrite(fd, "0", 1, 5);
	dprintf(fd, "z");
	if (close(fd) == -1) {
		errExit("close");
	}
	return (0);
}