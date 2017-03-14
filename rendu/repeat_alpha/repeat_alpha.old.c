#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_print_char(char c)
{
	int		n;

	if (c > 64 && c < 91)
	{
		n = c - 64;
		while (n > 0)
		{
			ft_putchar(c);
			n--;
		}
	}
	else
	{
		if (c > 96 && c < 123)
		{
			n = c - 96;
			while (n > 0)
			{
				ft_putchar(c);
				n--;
			}
		}
		else
			ft_putchar(c);
	}
}

int			main(int argc, char **argv)
{
	int		i;

	if (argc != 2)
	{
		ft_putchar('\n');
		return (1);
	}
	else
	{
		i = 0;
		while (argv[1][i] != '\0')
		{
			ft_print_char(argv[1][i]);
			i++;
		}
	}
	ft_putchar('\n');
	return (0);
}
