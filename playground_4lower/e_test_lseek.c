#include "../libft/libft.h"
#include "../libtlpi/tlpi_hdr.h"
#include <fcntl.h>

int main(int ac, char *av[])
{
	ac = 0; // silence warning
	int fd;
	char *file = malloc(100) ; 
	char *gnl_file;
	ssize_t bytes_read;
	ssize_t bytes_written;
	int i;
	off_t seek;

	fd = open(av[1], O_RDWR);
	i = 0;
	while ((bytes_read = read(fd, file, 1)))
	{
		ft_putnbr(i);
		ft_nl();
		i++;
	}
	// ft_putendl(file);
	// printf("Current offset: %lld\n", lseek(fd, 0, SEEK_CUR));
	// seek = lseek(fd, 10, SEEK_END);
	// ft_nl();
	// bytes_written = write(fd, "hey", strlen("hey")); // But why does this write 11mbs worth of HW's?
	// printf("After END_SEEK and write offset: %lld", lseek(fd, 0, SEEK_CUR));
	// ft_putnbr(seek = lseek(fd, 0, SEEK_SET));
	close(fd);
	exit(EXIT_SUCCESS);
}