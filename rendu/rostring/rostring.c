#include <stdlib.h>
#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int			ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\0')
		return (0);
	return (1);
}

int			ft_strlen(char *str)
{
	int		i;
	
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	return (i);
}

int			ft_countwords(char *str)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 1)
			{
				words++;
				while (ft_isspace(str[i]) == 1)
					i++;
			}
		else
			i++;
	}
	return (words);
}

char		*ft_makewords(char *str, int *j)
{
	char	*res;
	int		i;

	res = NULL;
	res = (char *)malloc(sizeof(char) * (ft_strlen(&str[*j]) + 1));
	i = 0;
	while (ft_isspace(str[*j]) == 1)
	{
		res[i] = str[*j];
		i++;
		*j = *j + 1;
	}
	res[i] = '\0';
	return (res);
}

char		**ft_split(char *str)
{
	char	**res;
	int		i;
	int		j;

	res = NULL;
	res = (char **)malloc(sizeof(char *) * (ft_countwords(str) + 1));
	i = 0;
	j = 0;
	while (i < ft_countwords(str))
	{
		if (ft_isspace(str[j]) == 1)
		{
			res[i] = ft_makewords(str, &j);
			i++;
		}
		else
			j++;
	}
	res[i] = NULL;
	return (res);
}

void		ft_rostring(char **str)
{
	int		i;

	i = 1;
	while (str[i] != NULL)
	{
		ft_putstr(str[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putstr(str[0]);
	ft_putchar('\n');
}

int			main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putchar('\n');
		return (1);
	}
	else
		ft_rostring(ft_split(argv[1]));
	return (0);
}
