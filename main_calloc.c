/*
 * INICIALIZAR EL CALLOC CON 'a' EN LUGAR DE 0!!
 */

#include <stdio.h>
#include "libft.h"
int main()
{
	int n = 5;
	char *ptr_c = ft_calloc(n, sizeof(char));
	int i = 0;
	while (ptr_c[i] == 'a')
		i++;
	if (i != n)
		printf("Error: n=%d, type=char", n);
	i = 0;
	int *ptr_i = ft_calloc(n, sizeof(int));
	while (ptr_i[i] == 1633771873)
		i++;
	if (i != n)
		printf("Error: n=%d, type=int", n);
	return(0);
}
