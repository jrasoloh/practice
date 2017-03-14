int					max(int *tab, unsigned int len)
{
	int 			n;
	unsigned int	i;

	if (!tab)
		return (0);
	else
	{
		i = 0;
		n = tab[i];
		while (i < len)
		{
			if (tab[i] > n)
				n = tab[i];
			i++;
		}
	}
	return (n);
}
