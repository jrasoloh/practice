#include <unistd.h>

void 		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_print_mirror(char c)
{
	if (c > 64 && c < 91)
		ft_putchar(155 - c);
	else
	{
		if (c > 96 && c < 123)
			ft_putchar(219 - c);
		else
			ft_putchar(c);
	}
}

int 		main(int argc, char **argv)
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
			ft_print_mirror(argv[1][i]);
			i++;
		}
		ft_putchar('\n');
	}
	return (0);
}
