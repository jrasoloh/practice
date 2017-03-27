#include <stdlib.h>
#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
		i++;
	return (i);
}

int			ft_countwords(char *str)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			words++;
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (words);
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

char		*ft_makeword(char *str, int *i)
{
	char	*res;
	int		k;

	k = 0;
	res = NULL;
	res = (char *)malloc(sizeof(char) * (ft_strlen(&str[*i]) + 1));
	while (str[*i] != ' ' && str[*i] != '\0' && str[*i] != '\t')
	{
		res[k] = str[*i];
		*i = *i + 1;
		k++;
	}
	res[k] = '\0';
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
	while (j < ft_countwords(str))
	{
		if (str[i] != ' ' && str[i] != '\0' && str[i] != '\t')
		{
			res[j] = ft_makeword(str, &i);
			j++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (res);
}


void		ft_revwstr(char *str)
{
	int		i;
	char	**res;

	res = ft_split(str);
	i = ft_countwords(str) - 1;
	while (i >= 1)
	{
		ft_putstr(res[i]);
		ft_putchar(' ');
		i--;
	}
	ft_putstr(res[i]);
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
		ft_revwstr(argv[1]);
	return (0);
}
