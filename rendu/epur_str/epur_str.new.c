#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int			ft_len_purstr(char *str)
{
	int		len;

	len = ft_strlen(str) - 1;
	while (len > 0 && (str[len] == ' ' || str[len] == '\t'))
		len--;
	return (len);
}

void		ft_epur(char *str)
{
	int		i;

	i = 0;
	while (i < ft_len_purstr(str))
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (str[i] != ' ' && str[i] != '\t')
		{
			ft_putchar(str[i]);
			if (str[i + 1] == ' ' || str[i + 1] == '\t')
				ft_putchar(' ');
		}
		i++;
	}
	ft_putchar(str[i]);
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
		ft_epur(argv[1]);
	return (0);
}
