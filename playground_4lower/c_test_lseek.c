#include "../libft/libft.h"
#include "tlpi_hdr.h"
#include <fcntl.h>

int main(int ac, char *av[])
{
	ac = 0; // silence warning
	int fd;
	char file[BUFSIZ];
	ssize_t bytes_read;
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
	ft_putnbr(seek = lseek(fd, 1, SEEK_CUR));
	i = 0;
	while (i < 10)
	{
		bytes_read = read(fd, file, 1);
		ft_putnbr(i++);
		ft_putendl(file);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}