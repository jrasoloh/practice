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
	int		pow;
	int		i;
	char	str[9];

	pow = 1;
	i = 0;
	while (pow != 256)
	{
		if (octet & pow)
			str[i] = 49;
		else
			str[i] = 48;
		pow *= 2;
		i++;
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
