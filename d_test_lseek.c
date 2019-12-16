#include "../libft/libft.h"
#include "tlpi_hdr.h"
#include <fcntl.h>

int main(int ac, char *av[])
{
	ac = 0; // silence warning
	int fd;
	char file[BUFSIZ];
	char *gnl_file;
	ssize_t bytes_read;
	ssize_t bytes_written;
	int i;
	off_t seek;

	fd = open(av[1], O_RDWR);
	i = 0;
	while (i < 10)
	{
		bytes_read = read(fd, file, 1);
		ft_putnbr(i++);
		ft_putendl(file);
	}
	ft_putnbr(seek = lseek(fd, 0, SEEK_END));
	ft_nl();
	bytes_written = write(fd, "Hello world", strlen("Hello world"));
	ft_putnbr(seek = lseek(fd, 0, SEEK_SET));
	if (get_next_line(fd, &gnl_file)) //Does the read in gnl get offset?
	{
		ft_putendl(gnl_file);
		ft_strdel(&gnl_file);
	}
	// i = 0;
	// while (i < 10)
	// {
	// 	bytes_read = read(fd, file, 1);
	// 	ft_putnbr(i++);
	// 	ft_putendl(file);
	// }
	close(fd);
	exit(EXIT_SUCCESS);
}