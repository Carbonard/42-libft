int	ft_isalnum(int c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
		return (8);
	else if ('0' <= c && c <= '9')
		return (8);
	else
		return (0);
}
