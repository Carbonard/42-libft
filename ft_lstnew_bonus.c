#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*item;

	item = malloc(sizeof(t_list));
	item->content = content;
	item->next = NULL;
	return (item);
}
