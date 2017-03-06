#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_rotone(char c)
{
	if ((c >64 && c < 90) || (c > 96 && c < 122))
		ft_putchar(c + 1);
	else
	{
		if (c == 90 || c == 122)
			ft_putchar(c - 25);
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
			ft_rotone(argv[1][i]);
			i++;
		}
	ft_putchar('\n');
	}
	return (0);
}
