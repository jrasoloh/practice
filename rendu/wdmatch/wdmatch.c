#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int 	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int			ft_match(char *s1, char *s2)
{
	int		i;
	int 	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] == s2[j])
			i++;
		if ((s2[j + 1] == '\0') && s1[i] != '\0')
			return (1);
		j++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_putchar('\n');
		return (1);
	}
	else
		if (ft_match(argv[1], argv[2]) == 0)
			ft_putstr(argv[1]);
		else
			ft_putchar('\n');
	return (0);
}
