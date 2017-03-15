#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_rot13_char(char c)
{
	if ((c > 64 && c < 78) || (c > 96 && c < 110))
		ft_putchar(c + 13);
	else
	{
		if ((c > 77 && c < 91) || (c > 109 && c < 123))
			ft_putchar(c - 13);
		else
			ft_putchar(c);
	}
}

void			ft_rot13(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_rot13_char(str[i]);
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
		ft_rot13(argv[1]);
	return (0);
}
