#include <stdlib.h>

int			ft_nblen(int n)
{
	int		i;

	i = 1;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char		*ft_itoa(int nbr)
{
	char	*res;
	int		i;
	int		sign;
	int		copy;
	int		len;

	if (nbr == -2147483648)
		return ("\n");
	else
	{
		copy = nbr;
		sign = 1;
		len = 0;
		if (copy < 0)
		{
			sign = -1;
			len++;
			copy = -1 * copy;
		}
		len = ft_nblen(copy) + len;
		res = (char *)malloc(sizeof(char) * (len + 1));
		i = 0;
		res[len] = '\0';
		len--;
		if (sign == -1)
		{
			res[i] = '-';
			i++;
		}
		while (i <= len)
		{
			res[len] = copy % 10 + 48;
			len--;
			copy = copy / 10;
		}
	}
	return (res);
}
