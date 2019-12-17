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
	bytes_written = write(fd, "Hello world", strlen("Hello world")); // But why does this write 11mbs worth of HW's?
	ft_putnbr(seek = lseek(fd, 0, SEEK_SET));
	if (get_next_line(fd, &gnl_file)) //Does the read in gnl get offset?
	{
		ft_putendl(gnl_file); // So the issue seems to be that when writing past the end of the file
		ft_strdel(&gnl_file); // that a nul byte gets inserted which seems to break gnl
		// This will require further investigation but it seems the problem is
		// that the offset for read starts at a nul byte and this breaks GNL, temp check just 
		// returns 1 the whole time which creates the infinite loop, I'll need to
		// investigate what happens with memory allocation in buff_rw.
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