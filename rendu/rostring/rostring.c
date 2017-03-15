#include <unistd.h>
#include <stdlib.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_purlen(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			len++;
			if (str[i + 1] == ' ' || str[i + 1] == '\t')
				len++;
		}
		i++;
	}
	return (len);
}

int			ft_count_words(char *str)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != ' ' && str[i] != '\t')
			&& (str[i + 1] == ' ' || str[i + 1] == '\t' || str[i + 1] == '\0'))
			words++;
		i++;
	}
	return (i);
}

void		ft_rostring(char *str)
{
	int		i;


}

int			main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putchar('\n');
		return (1);
	}
	else
		ft_rostring(argv[1]);
	return (0);
}
