#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h> /* for open() */
#include <sys/resource.h> /* for getrlimit() */
#include <sys/time.h> /* for getrlimit() */
#include <unistd.h> /* for close() and getopt() */
/* 	
*	include project local headers after system headers. 
*	This way you will know when your local headers are overwriting 
*	something from system headers/libraries:
*	Even though most of the std lib headers are included in 
*	tlpi_hdr.h is seems to be best practice to explicitly 
*	include all relavent headers incase you make changes.
*	This could be very relevant in big projects.
*/
#include "../libtlpi/tlpi_hdr.h"
#include "../libft/libft.h"

int		main(int argc, char *argv[])
{
	int opt;
	struct rlimit lim;
	unsigned int i;
	unsigned int num_file;
	int read_check;

	int a_flag = 0;
	char *line = NULL;
	int open_flags = O_CREAT | O_WRONLY | O_APPEND |O_TRUNC ;
	int file_perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | 
					S_IROTH | S_IWOTH;

	if (argc == 1)
	{
		dprintf(STDERR_FILENO, "Usage %s [-a] [file]\n", argv[0]);
				return (EXIT_FAILURE);
	}

	while ((opt = getopt(argc , argv, ":a")) != -1)
	{
		switch (opt)
		{
			case 'a':
				a_flag = 1;
				break;
			default:
				dprintf(STDERR_FILENO, "Usage %s [-a] [file]\n", argv[0]);
				return (EXIT_FAILURE);
		}
	}

	if (a_flag)
		open_flags = open_flags ^ O_TRUNC; 
	
	if (getrlimit(RLIMIT_NOFILE, &lim) == -1)
	{
		perror("getrlimit() error");
		exit(EXIT_FAILURE);
	}	

	num_file = argc - optind;
	// Args amount set to soft limit on open fds
	if (num_file > lim.rlim_cur)
	{
		dprintf(STDERR_FILENO, "Please provide less than %lld arguments.", lim.rlim_cur);
		return (EXIT_FAILURE);
	}
	// As long as you are not using C89 or ANSI-C you can define your variables wherever you want.
	// I would still like to know the effect if any during compilation.
	unsigned int fd[num_file]; 
	
	// Will this cast argc to unsigned in every time or only on the first call?
	for (i = 0 ; i < (unsigned int)argc; i++) 
		fd[i] = open(argv[optind + i], open_flags, file_perms);

	while ((read_check = get_next_line(STDIN_FILENO, &line)) != -1)
	{
		if (!read_check)
		{
			for (i = 0; i < num_file; i++)
				close (fd[i]);
			return (EXIT_SUCCESS);
		}
		for (i = 0; i < num_file; i++)
			ft_putendl_fd(line, fd[i]);
		ft_putendl_fd(line, STDOUT_FILENO); //prints with a newline char
		if (line)
			ft_strdel(&line); // free and point to NULL
	}
	
	dprintf(STDERR_FILENO, "Error reading from stdin.");
	return (EXIT_FAILURE);
}