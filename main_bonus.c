// To compare original functions with mine.
// compile ft_*.c main.c *.h && ./a.out
// make bonus && compile main_bonus.c libft.a && ./a.out'
#include <ctype.h> // isalpha...
#include <string.h> // str-cosa, mem-cosa,
#include <stdlib.h>
#include <limits.h>
#include "libft.h"

#include <stdio.h>

void	chnum(void *ptr)
{
	int	*n = (int *)ptr;
	*n *= 10;
}

int	main(int argc, char **argv)
{
	int		n;
	int		k;
	char	*string;
	int		*num;
	t_list	*list;
	t_list	*item;
	t_list	*item_aux;

	n = 10;
	string = calloc(n, sizeof(char));
	strcpy(string, "que");
	list = ft_lstnew(string);
	
	string = calloc(n, sizeof(char));
	strcpy(string, "hola");
	item = ft_lstnew(string);
	ft_lstadd_front(&list, item);
	
	string = calloc(n, sizeof(char));
	strcpy(string, "tal");
	item = ft_lstnew(string);
	ft_lstadd_back(&list, item);
	item_aux = item;
	
	string = calloc(n, sizeof(char));
	strcpy(string, "estas");
	item = ft_lstnew(string);
	ft_lstadd_back(&list, item);

	if(ft_lstsize(list) != 4)
		printf("Error: lstsize is wrong\n");

	ft_lstdelone(ft_lstlast(list), free);
	item_aux->next = NULL;

	ft_lstclear(&list, free);

	if (list != NULL)
		puts("Error: lstclear does not convert list in NULL.");
	
	num = calloc(1, sizeof(int));
	num[0] = 5;
	list = ft_lstnew(num);
	for(int i = 6; i < 10; i++)
	{
		num = calloc(1, sizeof(int));
		num[0] = i;
		item = ft_lstnew(num);
		ft_lstadd_back(&list, item);
	}
	for(int i = 4; i >= 0; i--)
	{
		num = calloc(1, sizeof(int));
		num[0] = i;
		item = ft_lstnew(num);
		ft_lstadd_front(&list, item);
	}
	item = list;
	if (*((int *)(item->content)) != 0)
		puts("Error: lstadd_front failed.");
	k = 1;
	while (k<=5)
	{
		item = item->next;
		if (*((int *)(item->content)) != k)
			puts("Error: lstadd_front failed.");
		k++;
	}
	while (k < 10)
	{
		item = item->next;
		if (*((int *)(item->content)) != k)
			puts("Error: lstadd_back failed.");
		k++;
	}

	ft_lstiter(list, chnum);
	item = list;
	if (*((int *)(item->content)) != 0)
		puts("Error: lstiter failed.");
	k = 1;
	while (item->next != NULL)
	{
		item = item->next;
		if (*((int *)(item->content)) != k * 10)
			puts("Error: lstiter failed.");
		k++;
	}

	if (item != ft_lstlast(list))
		puts("Error: lstlast failed");

	ft_lstclear(&list, free);
	(void) argc;
	printf("Use 'valgrind %s' for testing memory leaks.\n", argv[0]);
	puts("If there are memory leaks probably it's because of lstdelone or lstclear are wrong.");
}