#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_print_tab(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		print_bits(unsigned char octet)
{
	int		n;
	int		i;
	char	str[9];

	n = (int) octet;
	i = 7;
	while (n > 0 && i >= 0)
	{
		if (n % 2 == 1)
			str[i] = 49;
		else
			str[i] = 48;
		n = n / 2;
		i--;
	}
	str[8] = '\0';
	ft_print_tab(str);
}

int		main()
{
	print_bits(130);
	ft_putchar('\n');
	print_bits(129);
	ft_putchar('\n');
	print_bits(255);
	ft_putchar('\n');
	return (0);
}
