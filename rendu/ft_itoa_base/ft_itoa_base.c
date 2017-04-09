#include <stdlib.h>

int				ft_int_len(int n, int base)
{
	int			i;

	i = 1;
	while (n / base != 0)
	{
		i++;
		n = n / base;
	}
	return (i);
}

char			ft_val(int n)
{
	if (n > 9)
		return (n + 55);
	return (n + 48);
}

char			*ft_itoa(int n)
{
	char		*res;
	int			i;
	int			sign;
	int			len;
	
	if (n == -2147483648)
		return("-2147483648");
	else
	{
		i = 0;
		sign = 0;
		if (n < 0)
		{
			sign = 1;
			n = -1 * n;
		}
		len = ft_int_len(n, 10) + sign;
		res = (char *)malloc(sizeof(char) * (len + 1));
		res[len] = '\0';
		len--;
		if (sign == 1)
			res[0] = '-';
		while (len - sign >= 0)
		{
			res[len] = n % 10 + 48;
			n = n / 10;
			len--;
		}
	}
	return (res);
}

char			*ft_itoa_base(int value, int base)
{
	char		*res;
	int			i;

	if (base == 10)
		return (ft_itoa(value));
	else
	{
		if (value < 0)
			value = -1 * value;
		res = (char *)malloc(sizeof(char) * (ft_int_len(value, base) + 1));
		i = ft_int_len(value, base);
		res[i] = '\0';
		i--;
		while (0 <= i)
		{
			res[i] = ft_val(value % base);
			i--;
			value = value / base;
		}
	}
	return (res);
}
