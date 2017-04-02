#include <stdlib.h>
#include <stdio.h>

int				ft_int_base_len(int n, int base)
{
	int			i;

	i = 0;
	while (n / base > 0)
	{
		i++;
		n = n / base;
	}
	return (i);
}

char			ft_convert(int n)
{
	if (n > 10)
		return (n + 55);
	return (n + 48);
}

char			*ft_itoa(int nbr)
{
	char		*res;
	int			i;
	int			sign;
	int			copy;
	int			len;

	if (nbr == -2147483648)
		return ("-2147483648\n");
	copy = nbr;
	sign = 1;
	len = 0;
	if (copy < 0)
	{
		sign = -1;
		len++;
		copy = -1 * copy;
	}
	len = ft_int_base_len(copy, 10) + len;
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
	return (res);
}

char			*ft_itoa_base(int value, int base)
{
	char		*res;
	int			len;

	len = ft_int_base_len(value, base);
	res = (char *)malloc(sizeof(char) * (len + 1));
	res[len + 1] = '\0';
	while (len >= 0)
	{
		res[len] = ft_convert(value % base);
		len--;
		value = value / base;
	}
	return (res);
}
