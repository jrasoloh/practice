#include <stdio.h>
#include <stdlib.h>

void		fprime(int n)
{
	int		i;

	if (n == 1)
		printf("1");
	else
	{
		i = 2;
		while (i < n && n > 0)
		{
			if (n % i == 0)
			{
				printf("%d*", i);
				n = n / i;
			}
			else
				i++;
		}
		if (i == n)
			printf("%d", i);
	}
	printf("\n");
}

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n");
		return (1);
	}
	else
		fprime(atoi(argv[1]));
	return (0);
}
