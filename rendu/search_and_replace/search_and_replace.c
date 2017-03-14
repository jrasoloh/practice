#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

int				ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void			ft_replace(char *str, char a, char b)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == a)
			ft_putchar(b);
		else
			ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int				main(int argc, char **argv)
{
	if (argc != 4)
	{
		ft_putchar('\n');
		return (1);
	}
	else
	{
		if ((ft_strlen(argv[2]) != 1) || (ft_strlen(argv[3]) != 1))
		{
			ft_putchar('\n');
			return (1);
		}
		else
			ft_replace(argv[1], argv[2][0], argv[3][0]);
	}
	return (0);
}
