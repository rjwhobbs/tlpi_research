#include <fcntl.h>
#include "./libft/libft.h"
#include "./libtlpi/tlpi_hdr.h"

//A Basic implementation of 'cp'.
//TODO Error handling and optimization

int		main(int argc, char *argv[])
{
	(void)argc;
	int bytes_read;
	int bytes_written;
	int src_fd;
	int dst_fd;
	char buf[1];
	int count;
	
	count = 10;
	src_fd = open(argv[1], O_RDWR | O_CREAT,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
					S_IROTH | S_IWOTH);

	dst_fd = open(argv[2], O_RDWR | O_CREAT,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
					S_IROTH | S_IWOTH);

	while ((bytes_read = read(src_fd, buf, 1)))
		bytes_written = write(dst_fd, buf, 1);

	exit(EXIT_SUCCESS);
}
