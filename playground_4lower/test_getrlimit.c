#include <stdio.h>
#include <sys/resource.h>

int		main(void)
{
	struct rlimit lim;

	if (getrlimit(RLIMIT_NOFILE, &lim) == -1)
		printf("Errs\n");

	printf("%lld %lld\n", lim.rlim_cur, lim.rlim_max);
	return (0);
}