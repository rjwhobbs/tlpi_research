#include "../libft/libft.h"
#include "tlpi_hdr.h"
#include <fcntl.h>

int main(int ac, char *av[])
{
	int fd;
	char file[BUFSIZ];
	ssize_t bytes_read;
	int i;

	fd = open(av[1], O_RDWR);
	while (i < 2)
	{
		bytes_read = read(fd, file, 1);
		ft_putnbr(i++);
		ft_putendl(file);
	}
	write(fd, "X", 1);
	while (i < 5)
	{
		bytes_read = read(fd, file, 1);
		ft_putnbr(i++);
		ft_putendl(file);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}