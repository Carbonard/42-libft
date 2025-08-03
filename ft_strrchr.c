#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*chr;

	chr = (char *)s;
	while (*chr != '\0')
		chr++;
	while (*chr != c && chr != (char *)s)
		chr++;
	if (chr == (char *)s && c != *chr)
		return (NULL);
	return (chr);
}
