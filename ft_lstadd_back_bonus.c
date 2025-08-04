#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*item;

	item = *lst;
	while (item->next != NULL)
	{
		item = item->next;
	}
	item->next = new;
}
