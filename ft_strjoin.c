#include <stdlib.h>

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	size1;
	size_t	size2;
	size_t	i;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	joined = malloc((size1 + size2 + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		joined[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < size2)
	{
		joined[size1 + i] = s2[i];
		i++;
	}
	return (joined);
}
