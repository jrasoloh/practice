#include <stdlib.h>

int				ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\0' || c == '\n')
		return (0);
	else
		return (1);
}

int				ft_strlen(char *str)
{
	int			i;
	
	i = 0;
	while (ft_isspace(str[i]) == 1)
		i++;
	return (i);
}

int				ft_countwords(char *str)
{
	int			i;
	int			words;

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

char			*ft_makeword(char *str, int *j)
{
	char		*res;
	int			i;

	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(&str[*j]) + 1));
	while (ft_isspace(str[*j]) == 1)
	{
		res[i] = str[*j];
		i++;
		*j = *j + 1;
	}
	res[i] = '\0';
	return (res);
}

char			**ft_split(char *str)
{
	char		**res;
	int			i;
	int			j;

	res = (char **)malloc(sizeof(char *) * (ft_countwords(str) + 1));
	i = 0;
	j = 0;
	while (i < ft_countwords(str))
	{
		if (ft_isspace(str[j]) == 1)
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
