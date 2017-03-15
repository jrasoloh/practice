#include <stdlib.h>
#include <stdio.h>

int			ft_pgcd(int a, int b)
{
	if ((a - b == 1) 
		|| (a == 0 && b != 0) 
		|| (a != 0 && b == 0))
		return (1);
	else
	{
		if (a - b == b)
			return (b);
		else
		{
			if (b - a == a)
				return (a);
			else
			{
				if (a > b)
					return (ft_pgcd((a - b), b));
				else 
					return (ft_pgcd((b - a), a));
			}
		}
	}
}


int			main(int argc, char **argv)
{
	int a;
	int b;

	if (argc != 3)
	{
		printf("\n");
		return (1);
	}
	else
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		printf("%d\n", ft_pgcd(a, b));
	}
	return (0);
}
