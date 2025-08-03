#include <stddef.h>

size_t	ft_strlen(const char *str);

static int	aux_cmp(const char *s1, const char *s2, size_t n)
{
	long unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s2[i] != 0 && i < n)
		i++;
	if (i == n || s2[i] == 0)
		return (0);
	return (s1[i] - s2[i]);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	size1;
	size_t	i;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	size1 = ft_strlen(s1);
	i = 0;
	while (i < size1)
	{
		if (aux_cmp(s1 + i, s2, len) == 0)
			return (s1 + i);
		i++;
	}
	return (NULL);
}
