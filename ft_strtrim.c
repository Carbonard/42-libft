#include <stdlib.h>

static int	char_in_str(const char c, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*trimmed;

	i = 0;
	while (char_in_str(s1[i], set))
		i++;
	start = i;
	while (s1[i] != '\0')
		i++;
	while (char_in_str(s1[i], set))
		i--;
	end = i;
	trimmed = malloc((end - start +1) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	i = start;
	while (i <= end)
	{
		trimmed[i - start] = s1[i];
		i++;
	}
	return (trimmed);
}
