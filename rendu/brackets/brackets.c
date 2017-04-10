#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void			ft_putstr(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int				ft_isbracket(char c)
{
	if (c == '(' || c == ')'
		|| c == '[' || c == ']'
		|| c == '{' || c == '}')
		return (0);
	return (1);
}

int				ft_tax(char c)
{
	if (c == '(')
		return (2);
	if (c == ')')
		return (-2);
	if (c == '[')
		return (3);
	if (c == ']')
		return (-3);
	if (c == '{')
		return (5);
	if (c == '}')
		return (-5);
	return (0);
}

int				ft_value(char *str)
{
	int			i;
	int			value;
	int			rank;

	i = 0;
	value = 0;
	rank = 0;
	while (str[i])
	{
		if (ft_isbracket(str[i]) == 1)
			i++;
		else
		{
			if (rank == 0 && (str[i] == ']' || str[i] == ')' || str[i] == '}'))
				return (-666);
			if (str[i] == '(' || str[i] == '{' || str[i] == '[')
				rank++;
			value = value + rank * ft_tax(str[i]);
			if (str[i] == ')' || str[i] == ']' || str[i] == '}')
				rank--;
			i++;
		}
	}
	return (value);
}

void			brackets(char *str)
{
	if (ft_value(str) != 0)
		ft_putstr("Error\n");
	else
		ft_putstr("OK\n");
}

int				main(int argc, char **argv)
{
	int			i;
	
	if (argc < 2)
	{
		ft_putchar('\n');
		return (1);
	}
	else
	{
		i = 1;
		while (argv[i] != NULL)
		{
			brackets(argv[i]);
			i++;
		}
	}
	return (0);
}
