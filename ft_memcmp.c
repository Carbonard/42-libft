#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char				*ptr1;
	char				*ptr2;
	long unsigned int	i;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	i = 0;
	while (ptr1[i] == ptr2[i] && ptr1[i] != 0 && i < n)
		i++;
	if (i == n)
		return (0);
	return (ptr1[i] - ptr2[i]);
}
