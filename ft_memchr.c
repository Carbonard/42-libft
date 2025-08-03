#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*chr;
	size_t	i;

	chr = (char *)s;
	i = 0;
	while (chr[i] != c && i < n)
	{
		i++;
	}
	if (i == n)
		return (NULL);
	return ((void *)(chr + i));
}
