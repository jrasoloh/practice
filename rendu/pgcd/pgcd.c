#include <stdlib.h>
#include <stdio.h>

int			ft_pgcd(int a, int b)
{
	if (a - b == b)
		return (b);
	if (b - a == a)
		return (a);
	if ((a == 0 && b != 0) || (a != 0 && b == 0))
		return (1);
	if (a > b)
		ft_pgcd((a - b), b);
	else 
		ft_pgcd((b - a), a);
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
