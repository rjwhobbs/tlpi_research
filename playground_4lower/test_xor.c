#include <stdio.h>

int 	main(void)
{
	int a, b, c;

	a = 1, b = 1, c = 1;

	c = c ^ b;
	printf("%d\n", c);
	c = c ^ b; 
	printf("%d\n", c);
}