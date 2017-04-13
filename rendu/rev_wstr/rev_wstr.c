#include <unistd.h>
#include <stdlib.h>

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
	if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
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
			while (ft_isspace(str[i]) == 1 && str[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}

char		*ft_makeword(char *str, int *j)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (ft_strlen(&str[*j]) + 1));
	i = 0;
	while (ft_isspace(str[*j]) == 1)
	{
		res[i] = str[*j];
		*j = *j + 1;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char		**ft_split(char *str)
{
	char	**res;
	int		i;
	int		j;

	res = (char **)malloc(sizeof(char *) * (ft_countwords(str) + 1));
	i = 0;
	j = 0;
	while (i < ft_countwords(str))
	{
		if (ft_isspace(str[j]) == 1)
			while (ft_isspace(str[j]) == 1 && str[j])
			{
				res[i] = ft_makeword(str, &j);
				i++;
			}
		else
			j++;
	}
	res[i] = NULL;
	return (res);
}

void		rev_wstr(char *str)
{
	int		i;
	char	**res;

	res = ft_split(str);
	i = ft_countwords(str) - 1;
	while (i > 0)
	{
		ft_putstr(res[i]);
		ft_putchar(' ');
		i--;
	}
	ft_putstr(res[0]);
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
		rev_wstr(argv[1]);
	return (0);
}
