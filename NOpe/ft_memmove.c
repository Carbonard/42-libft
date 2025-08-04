#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	cpy[n];

	i = 0;
	while (i < n)
	{
		cpy[i] = *(((char *) src) + i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		*(((char *) dest) + i) = *(((char *) cpy) + i);
		i++;
	}
	return (dest);
}