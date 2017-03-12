#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

int				ft_twin(char c, char *str, int n)
{
	int			i;

	i = 0;
	while (i < n)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void			ft_inter(char *s1, char *s2)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		if (ft_twin(s1[i], s1, i) == 1)
			i++;
		if (s1[i] == '\0')
			break;
		while (s1[i] != '\0' && s2[j] != '\0')
		{
			if ((s1[i] == s2[j]) 
				&& (ft_twin(s2[j], s2, j) == 0)
				&& (ft_twin(s1[i], s1, i) == 0))
			{
				ft_putchar(s1[i]);
				break;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int				main(int argc, char **argv)
{
	if (argc != 3)
		ft_putchar('\n');
	else
	{
		ft_inter(argv[1], argv[2]);
		ft_putchar('\n');
	}
	return (0);
}
