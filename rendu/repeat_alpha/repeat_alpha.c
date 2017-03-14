#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_print_char(char c)
{
	int			i;

	if (c > 64 && c < 91)
	{
		i = 64;
		while (c - i > 0)
		{
			ft_putchar(c);
			i++;
		}
	}
	else
	{
		if (c > 96 && c < 123)
		{
			i = 96;
			while (c - i > 0)
			{
				ft_putchar(c);
				i++;
			}
		}
		else
			ft_putchar(c);
	}
}

void			ft_print(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_print_char(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int				main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (1);
	}
	else
		ft_print(argv[1]);
	return (0);
}
