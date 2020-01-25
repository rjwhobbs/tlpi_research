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
	n3 = ft_lstnew("BISCUITS", sizeof("BISCUITS"));

	start = NULL;
	ft_lstadd(&start, n3);
	ft_lstadd(&start, n2);
	ft_lstadd(&start, n1);

	ft_lstdel(&start, ft_del);
	while (start != NULL) {
		ft_putendl(start->content);
		ft_putnbr(start->content_size);
		ft_putchar('\n');
		start = start->next;
	}
	return (0);
}