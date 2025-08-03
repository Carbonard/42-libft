#include <stddef.h>

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	i_dst;
	size_t	i_src;

	size_dst = ft_strlen(dst);
	if (size < size_dst)
		size_dst = size;
	size_src = ft_strlen(src);
	i_src = 0;
	i_dst = size_dst;
	if (size > 0)
	{
		while (i_dst < size - 1)
		{
			dst[i_dst] = src[i_src];
			i_dst++;
			i_src++;
		}
	}
	if (i_dst < size)
		dst[i_dst] = '\0';
	return (size_dst + size_src);
}
