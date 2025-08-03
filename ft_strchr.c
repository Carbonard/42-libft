#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	char	*chr;

	chr = (char *)s;
	while (*chr != c && *chr != '\0')
		chr++;
	if (*chr == '\0' && c != 0)
		return (NULL);
	return (chr);
}
