#include "../libft/libft.h"

void	ft_del(void *content, size_t size) {
	(void)size;
	free(content);
}

void	ft_lstdel2(t_list **alsti, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alsti && *alsti)
	{
		while (*alsti)
		{
			temp = *alsti;
			*alsti = (*alsti)->next;
			del(temp->content, temp->content_size);
			free(temp);
			temp = NULL;
		}
	}
}

int	main(int ac, char **av) {

	t_list *n1;
	t_list *n2;
	t_list *n3;
	t_list *start;

	n1 = ft_lstnew("ice cream", sizeof("ice cream"));
	n2 = ft_lstnew("candy", sizeof("candy"));

	start = NULL;

	// ft_putendl(n1->content);
	n1->next = n2;
	ft_lstdel2(&n1, ft_del);
	// n3 = ft_lstnew("BISCUITS", sizeof("BISCUITS"));
	if (n1->content == NULL) {
		ft_putendl("Here");
	}
	return (0);
}