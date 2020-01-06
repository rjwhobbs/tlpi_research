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
	char *line;

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

	unsigned int fd[fd_buf]; // What is the effect of declaring vars here instead of at the begining

	if (opt_check)
		open_flags = open_flags ^ O_TRUNC; 
	
	while (argv[optind + i])
	{
		fd[i] = open(argv[optind + i], open_flags, file_perms);
		i++;
	}

	// How can I close fds if the program only closes with sigint?
	while (get_next_line(STDIN_FILENO, &line) != -1)
	{
		i = 0;
		while (i < fd_buf)
		{
			ft_putendl_fd(line, fd[i]);
			i++;
		}
		ft_putendl_fd(line, STDOUT_FILENO); //prints with a newline char
		free(line);
	}
		 
	exit(EXIT_FAILURE);
}