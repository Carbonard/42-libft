int ft_isdigit(char *str)
{
	while (*str != '\0')
	{
		if (!('0' <= *str && *str <= '1'))
			return (0);
	}
	return (1);
}