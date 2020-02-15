#include <stdlib.h>

#include "../libft/libft.h"
#include "../libtlpi/tlpi_hdr.h"

int		main(void) {

	int fd;
	char template[] = "/tmp/somestringXXXXXX";
	fd = mkstemp(template);
	if (fd == -1)
		errExit("mkstemp");
	printf("Generated filename was: %s\n", template);
	unlink(template); 	/* Name disappears immediately, but the file
						is removed only after close() 
						Use file I/O system calls - read(), write(), and so on */
	if (close(fd) == -1)
		errExit("close");
	return (0);
}