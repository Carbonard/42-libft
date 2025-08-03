int ft_iisalnum(char *str)
{
	while (*str != '\0')
	{
		if (!(('a' <= *str && *str <= 'z') || ('A' <= *str && *str <= 'Z') || ('0' <= *str && *str <= '1')))
			return (0);
	}
	return (1);
}