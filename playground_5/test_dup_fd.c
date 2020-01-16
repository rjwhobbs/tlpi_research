#include <fcntl.h>

#include "../libft/libft.h"
#include "../libtlpi/tlpi_hdr.h"

int		main(int argc, char *argv[]) {
	int newfd = dup(STDOUT_FILENO);

	dprintf(newfd, "Words on a screen %d", newfd);
	return (0);
}