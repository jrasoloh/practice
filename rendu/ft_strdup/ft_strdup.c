#include <stdlib.h>

int				ft_strlen(char *str)
{
	int			i;

	if (!str)
		return (0);
	else
	{
		i = 0;
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

char			*ft_malloc(char *s1)
{
	char		*s2;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	return (s2);
}


char			*ft_strdup(char *src)
{
	char		*str;
	int			i;

	if (!src)
		return (NULL);
	else
	{
		str = ft_malloc(src);
		i = 0;
		while (src[i] != '\0')
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
