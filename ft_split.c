#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set);

static size_t	get_arr_size(char const *s, char c)
{
	size_t	i;
	size_t	arr_size;

	i = 0;
	arr_size = 0;
	if (s[0] != '\0')
		arr_size++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			arr_size++;
			while (s[i] == c)
				i++;
		}
		else
		{
			i++;
		}
	}
	return (arr_size);
}

static void	allocate_mem(const char *s, char c, char **spl)
{
	size_t	i;
	size_t	str_size;
	size_t	arr_size;

	i = 0;
	str_size = 0;
	arr_size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && str_size != 0)
		{
			spl[arr_size] = malloc((str_size + 1) * sizeof(char));
			arr_size++;
			str_size = 0;
		}
		else if (s[i] != c)
			str_size++;
		i++;
	}
	if (str_size != 0)
		spl[arr_size] = malloc((str_size + 1) * sizeof(char));
}

static void	fill_array(const char *s, char c, char **spl)
{
	size_t	i;
	size_t	str_size;
	size_t	arr_size;

	i = 0;
	str_size = 0;
	arr_size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && str_size != 0)
		{
			spl[arr_size++][str_size] = '\0';
			str_size = 0;
		}
		else if (s[i] != c)
			spl[arr_size][str_size++] = s[i];
		i++;
	}
	if (str_size != 0)
	{
		spl[arr_size][str_size] = '\0';
		arr_size++;
	}
	spl[arr_size] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	char	*s_trimmed;
	char	*charset;
	size_t	arr_size;

	charset = malloc(2 * sizeof(char));
	charset[0] = c;
	charset[1] = '\0';
	s_trimmed = ft_strtrim(s, charset);
	free(charset);
	arr_size = get_arr_size(s_trimmed, c);
	splitted = malloc((arr_size + 1) * sizeof(char *));
	if (splitted == NULL)
		return (NULL);
	allocate_mem(s_trimmed, c, splitted);
	fill_array(s_trimmed, c, splitted);
	free(s_trimmed);
	return (splitted);
}
