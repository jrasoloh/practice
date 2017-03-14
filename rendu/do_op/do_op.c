#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int			ft_op(int a, int b, char c)
{
	if (c == '+')
		return (a + b);
	else 
	{
		if (c == '-')
			return (a - b);
		else
		{
			if (c == '*')
				return (a * b);
			else 
			{
				if (c == '/')
					return (a / b);
				else
					return (a % b);
			}
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int		a;
	int		b;
	
	if (argc != 4)
	{
		write(1, "\n", 1);
		return (1);
	}
	else
	{
		a = atoi(argv[1]);
		b = atoi(argv[3]);
		printf("%d\n", ft_op(a, b, argv[2][0]));
	}
	return (0);
}
