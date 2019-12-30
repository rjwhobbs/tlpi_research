#include "../libtlpi/tlpi_hdr.h"

struct X
{
	int a;
};

void set_value(struct X *this, int v)
{
	this->a = v;
};


int main(void)
{
	struct X x;
	set_value(&x, 5);
	printf("%d\n", x.a);
	exit(EXIT_SUCCESS);
}

