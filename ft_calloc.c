#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i * sizeof(char) < size * nmemb)
	{
		*(((char *)ptr) + i) = 0;
		i++;
	}
	return (ptr);
}
