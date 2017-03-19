#include <stdlib.h>

char		*cas()
{
	char	*str = "-2147483648";

	return (str);
}

int			ft_len(int n)
{
	int		len;
	
	len = 1;
	while (n / 10 > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		len;
	int		i;
	int		copy;
	int		sign;

	copy = nbr;
	sign = 1;
	len = 0;
	if (nbr == -2147483648)
	{
		str = cas();
		return (str);
	}
	if (nbr < 0)
	{
		len = 1;
		sign = -1;
		copy = -1 * nbr;
	}
	len = len + ft_len(copy);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	i = 0;
	if (sign == -1)
	{
		str[i] = '-';
		i++;
	}
	len--;
	while (len >= i)
	{
		str[len] = (copy % 10) + 48;
		copy = copy / 10;
		len--;
	}
	return (str);
}
