#include <stdio.h>
#include <stdlib.h>

void				ft_swap(int *a, int *b)
{
	int				tmp;

		tmp = *a;
		*a = *b;
		*b = tmp;
}

void				ft_print_tab(int *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("%d\n", tab[i]);
}

int					ft_sorted(int *tab, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void				sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	min;

	i = 0;
	j = 1;
	min = 0;
	while (j < size && ft_sorted(tab, size) == 1)
	{
		while (j < size)
		{
			if (tab[j] < tab[min])
				min = j;
			j++;
		}
		ft_swap(&tab[i], &tab[min]);
		i++;
		min = i;
		j = i + 1;
	}
}

int					main()
{
	int				*tab;
	unsigned int	size;

	size = 7;
	tab = (int *)malloc(sizeof(int) * size);
	tab[0] = 42;
	tab[1] = 3;
	tab[2] = 4;
	tab[3] = 5;
	tab[4] = 10;
	tab[5] = 5;
	tab[6] = 31;
	sort_int_tab(tab, size);
	ft_print_tab(tab, size);
	return (0);
}
