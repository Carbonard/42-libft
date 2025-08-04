#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*item;
	t_list	*tmp_item;

	item = *lst;
	while (item->next != NULL)
	{
		tmp_item = item;
		item = item->next;
		del(tmp_item->content);
		free(tmp_item);
	}
	del(item->content);
	free(item);
	*lst = NULL;
}
