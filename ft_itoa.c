#include <stdlib.h>

static char	*create_str(char *num_arr, int neg, int length)
{
	char	*str_num;
	int		i;

	str_num = malloc((length + neg + 1) * sizeof(char));
	i = 0;
	if (neg)
	{
		str_num[0] = '-';
		i++;
	}
	while (i - neg < length)
	{
		str_num[i] = num_arr[length - 1 - (i - neg)];
		i++;
	}
	str_num[i] = '\0';
	return (str_num);
}

char	*ft_itoa(int n)
{
	char	num_arr[20];
	long	number;
	int		neg;
	int		length;

	number = (long) n;
	neg = 0;
	if (number < 0)
	{
		number = -number;
		neg = 1;
	}
	length = 0;
	if (number == 0)
	{
		num_arr[0] = '0';
		length = 1;
	}
	while (number > 0)
	{
		num_arr[length++] = number % 10 + '0';
		number /= 10;
	}
	return (create_str(num_arr, neg, length));
}
