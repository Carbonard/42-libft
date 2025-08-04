#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long			num;
	char			number[20];
	unsigned int	i;

	num = (long)n;
	if (num < 0)
	{
		num = -num;
		write(fd, "-", 1);
	}
	else if (num == 0)
		write(fd, "0", 1);
	i = 0;
	while (num > 0)
	{
		number[i] = num % 10 - '0';
		num /= 10;
		i++;
	}
	while (i-- > 0)
		write(fd, number + i, 1);
}
