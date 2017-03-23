#include <stdlib.h>
#include <stdio.h>

int				ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int				ft_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\0')
		return (0);
	else
		return (1);
}

int				ft_countwords(char *str)
{
	int			i;
	int			words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (ft_space(str[i]) == 1)
		{
			words++;
			while ((ft_space(str[i]) == 1) && str[i])
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

	res = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	while (ft_space(str[*j]) == 1)
	{
		res[i] = str[*j];
		*j = *j + 1;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char			**ft_split(char *str)
{
	char		**res;
	int			i;
	int			j;

	res = NULL;
	res = (char **)malloc(sizeof(char *) * (ft_countwords(str) + 1));
	i = 0;
	j = 0;
	while (i < ft_countwords(str))
	{
		if (ft_space(str[j]) == 1)
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

int				main()
{
	int			len;
	int			i;
	char		**pr;
	char		*oo = "bonjour je suis bien trop bon";
		
	len = ft_countwords(oo);
	pr = ft_split(oo);
	i = 0;
	printf("nbre de mots = %d\n", len);
	while (i < len)
	{
			printf("mot num%d = %s\n", i + 1, pr[i]);
			i++;
	}
	return (0);
}
