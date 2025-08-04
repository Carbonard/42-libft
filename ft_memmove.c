#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

static void	special_case(char *dst, char *src, size_t n, size_t overlap)
{
	char	tmp1;
	char	tmp2;
	size_t	i;
	size_t	k;

	i = 0;
	while (i < overlap)
	{
		k = 0;
		tmp1 = src[i];
		while (i + k < n)
		{
			tmp2 = dst[i + k];
			dst[i + k] = tmp1;
			tmp1 = tmp2;
			k += overlap;
		}
		i++;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*chr_dst;
	char	*chr_src;
	size_t	i;

	chr_dst = (char *)dest;
	chr_src = (char *)src;
	i = 0;
	while (i < n)
	{
		if (chr_src + i == chr_dst)
		{
			special_case(chr_dst, chr_src, n, i);
			return (dest);
		}
		i++;
	}
	return (ft_memcpy(dest, src, n));
}
