#include "../libft/libft.h"

void	ft_del(void *content, size_t size) {
	(void)size;
	free(content);
}

int	main(int ac, char **av) {

	t_list *n1;
	t_list *n2;
	t_list *n3;
	t_list *start;

	n1 = ft_lstnew("ice cream", sizeof("ice cream"));
	n2 = ft_lstnew("candy", sizeof("candy"));

	start = NULL;

	ft_putendl(n1->content);
	n1->next = n2;
	free(n1);
	n3 = ft_lstnew("BISCUITS", sizeof("BISCUITS"));
	ft_putendl(n1->content);
	return (0);
}