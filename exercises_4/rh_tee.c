#include "../libtlpi/tlpi_hdr.h"
#include "../libft/libft.h"
#include <ctype.h>
#include <fcntl.h>

int		main(int argc, char *argv[])
{
	int opt;
	int open_flags;
	int file_perms;
	int opt_check;
	struct rlimit lim;
	unsigned int i;
	unsigned int fd_buf;

	i = 0;
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
	
	if (getrlimit(RLIMIT_NOFILE, &lim) == -1)
	{
		ft_putendl("getrlimit() err");
		exit(EXIT_FAILURE);
	}	

	fd_buf = argc - optind;
	if (fd_buf > lim.rlim_cur)
	{
		ft_putendl("Too many args");
		exit(EXIT_FAILURE);
	}

	ft_putnbr(fd_buf);
	ft_nl();
	unsigned int fd[fd_buf];

	if (opt_check)
		open_flags = open_flags ^ O_TRUNC; 
	
	while (argv[optind + i])
	{
		fd[i] = open(argv[optind + i], open_flags, file_perms);
		i++;
	}

	i = 0;
	while (i < fd_buf)
		close(fd[i++]);
		 
	exit(EXIT_SUCCESS);
}