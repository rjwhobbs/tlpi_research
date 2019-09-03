#include "../libft/libft.h"
#include <stdio.h>

int display();

int __attribute__((constructor)) display();  
int __attribute__((destructor)) main();  
#pragma GCC poison printf 

int main(void) 
{

   ft_putendl("\nI am in main function");
   return 0;
}

int display(void) 
{
	printf("I am poison.");
	ft_putendl("\nI am in display function");
	return 0;
}