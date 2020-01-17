#include <fcntl.h>
#include <sys/uio.h>

#include "../libft/libft.h"
#include "../libtlpi/tlpi_hdr.h"

int		main(int argc, char *argv[]) {

	struct iovec iov[3];
	char str_one[50];
	char str_two[50];
	char str_three[50];
	int num_read;
	int open_flags = O_RDONLY ;
	int file_perms = S_IRUSR | S_IWUSR ;
	int i;

	int fd = open(argv[1], open_flags, file_perms);

	iov[0].iov_base = str_one;
	iov[0].iov_len = 5;

	iov[1].iov_base = str_two;
	iov[1].iov_len = 5;

	iov[2].iov_base = str_three;
	iov[2].iov_len = 5;

	num_read = readv(fd, iov, 3);
	if (num_read == -1) {
		close(fd);
		errExit("readv");
	}

	for (i = 0; i < 3; i++) {
		printf("%d:\n%s\n", i, iov[i].iov_base);
	}

	if (close(fd) == -1) {
		errExit("close");
	}
	return (0);
}