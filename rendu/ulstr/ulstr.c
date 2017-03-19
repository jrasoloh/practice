#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_switch(char c)
{
	if (c > 64 && c < 91)
		ft_putchar(c + 32);
	else
	{
		if (c > 96 && c < 123)
			ft_putchar(c - 32);
		else
			ft_putchar(c);
	}
}

void		ft_ulstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_switch(str[i]);
		i++;
	}
	ft_putchar('\n');	
}

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putchar('\n');
		return (1);
	}
	else
		ft_ulstr(argv[1]);
	return (0);
}
