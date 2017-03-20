#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

char		ft_cap_char(char c)
{
	if (c > 96 && c < 123)
		return (c - 32);
	return (c);
}

char		ft_small(char c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	else
		return (c);
}

void		ft_capitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0')
			ft_putchar(ft_cap_char(str[i]));
		else
			ft_putchar(ft_small(str[i]));
		i++;
	}
	ft_putchar('\n');
}

int			main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
	{
		ft_putchar('\n');
		return (1);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			ft_capitalize(argv[i]);
			i++;
		}
	}
	return (0);
}
