#include <stdio.h>

int			is_power_of_2(unsigned int n)
{
	int		i;
	int		nb;

	nb = (int) n;
	if (nb < 2)
		return (1);
	else
	{
		i = 2;
		while (i < nb)
			i = i *2;
		if (i != nb)
			return (1);
	}
	return (0);
}

int		main()
{
	printf("252 est une puissance de 2? si 0 oui %d \n", is_power_of_2(252));
	return (0);
}
