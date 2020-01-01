#include <stdio.h>
#include <ctype.h>

#define min(m, n) ((m) < (n) ? (m) : (n))
#define max(m, n) ((m) > (n) ? (m) : (n))
#define printable(ch) (isprint((unsigned char) ch) ? ch : '#')

int		main(void)
{
	int y = 'z';
	printf("%d", y);
	printf("%d\n", max('X','x'));
	printf("%c\n", printable(y));
	return (0);
}