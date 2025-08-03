#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str);
int		ft_strlcpy(char *dst, const char *src, size_t dsize);

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		len;

	len = ft_strlen(str);
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, str, len + 1);
	return (dup);
}
