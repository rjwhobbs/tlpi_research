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
	int read_check;

	line = NULL;
	opt_check = 0;
	open_flags = O_CREAT | O_WRONLY | O_APPEND |O_TRUNC ;
	file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | 
					S_IROTH | S_IWOTH;

	if(argc == 1)
		return (EXIT_FAILURE);

	while ((opt = getopt(argc , argv, ":a")) != -1)
	{
		if (opt == 'a')
			opt_check = 1;
		if (opt == '?')
		{
			dprintf(STDERR_FILENO, "Usage %s [-a] [file]\n", argv[0]);
			exit(EXIT_FAILURE);
		}
	}

	if (opt_check)
		open_flags = open_flags ^ O_TRUNC; 
	
	if (getrlimit(RLIMIT_NOFILE, &lim) == -1)
	{
		perror("getrlimit() error");
		exit(EXIT_FAILURE);
	}	

	fd_buf = argc - optind;
	// Args amount set to soft limit on open fds
	if (fd_buf > lim.rlim_cur)
	{
		dprintf(STDERR_FILENO, "Please provide less than %lld arguments.", lim.rlim_cur);
		exit(EXIT_FAILURE);
	}

	unsigned int fd[fd_buf]; // What is the effect of declaring vars here instead of at the begining of the program?
	i = 0;

	for ( ; i < (unsigned int)argc; i++)
		fd[i] = open(argv[optind + i], open_flags, file_perms);

	while ((read_check = get_next_line(STDIN_FILENO, &line)) != -1)
	{
		if (!read_check)
			exit(EXIT_SUCCESS);
		i = 0;
		while (i < fd_buf)
		{
			ft_putendl_fd(line, fd[i]); //prints with a newline char
			i++;
		}
		ft_putendl_fd(line, STDOUT_FILENO); //prints with a newline char
		if (line)
			ft_strdel(&line); // free and point to NULL
	}
	
	dprintf(STDERR_FILENO, "Error reading from stdin.");
	exit(EXIT_FAILURE);
}