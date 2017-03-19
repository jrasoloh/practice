#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		ft_putnb(int n)
{
	if (n / 10 == 0)
		ft_putchar(n + 48);
	else
	{
		ft_putnb(n / 10);
		ft_putchar(n % 10 + 48);
	}
}

int			ft_atoi(char *str)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (str[i] != '\0')
	{
		n = n * 10 + (str[i] - 48); 
		i++;
	}
	return (n);
}

void		ft_calc(int i, int n)
{
	ft_putnb(i);
	ft_putstr(" x ");
	ft_putnb(n);
	ft_putstr(" = ");
	ft_putnb(i * n);
	ft_putchar('\n');	
}

void		ft_tabmult(int n)
{
	int		i;

	i = 1;
	while (i < 10)
	{
		ft_calc(i, n);
		i++;
	}
}

int			main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putchar('\n');
		return (1);
	}
	else
		ft_tabmult(ft_atoi(argv[1]));
	return (0);
}
