#include "../libtlpi/tlpi_hdr.h"

int		main(int ac, char *av[])
{
	(void)ac;
	printf("%d\n", getInt(av[1], GN_BASE_8, av[1]));
	return (0);
}