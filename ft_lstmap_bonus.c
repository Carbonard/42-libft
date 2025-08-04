#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	new_list = ft_lstnew(f(lst->content));
	while (lst->next != NULL)
	{
		lst = lst->next;
		ft_lstadd_back(&new_list, (f(lst->content)));
	}
	(void) (*del);
	return (new_list);
}
