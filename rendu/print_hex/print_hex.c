#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_print_int(int n)
{
	if (n % 16 >= 0 && n % 16 < 10)
		ft_putchar(n % 16 + 48);
	else
		ft_putchar(n % 16 + 87);
}

void			ft_print_hex(int n)
{
	int			div;
	int			quo;
	int			reste;

	div = n;
	quo = 0;
	while (n > quo)
	{
		while (div > quo)
		{
			reste = div % 16;
			div = div / 16;
		}
		quo = div * 16 + reste;
		ft_print_int(reste);
		div = n;
	}
	ft_putchar('\n');
}

int				ft_atoi(char *str)
{
	int			n;
	int			i;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		n = n * 10 + str[i] - 48;
		i++;		
	}
	return (n);
}

int				main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (1);
	}
	else
	{
		if (ft_atoi(argv[1]) == 0)
		{
			ft_putchar('0');
			ft_putchar('\n');
		}
		else
			ft_print_hex(ft_atoi(argv[1]));
	}
	return (0);
}
