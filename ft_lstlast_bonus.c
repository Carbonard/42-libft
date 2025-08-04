#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*item;

	item = lst;
	while (item->next != NULL)
	{
		item = item->next;
	}
	return (item);
}
