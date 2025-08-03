int	ft_atoi(const char *nptr)
{
	long	num;
	int		sgn;
	int		i;

	i = 0;
	sgn = 1;
	if (nptr[i] == '-')
		sgn = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	num = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return ((int)(num * sgn));
}
