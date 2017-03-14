#include <unistd.h>
#include <stdio.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_print_num(int n)
{
	if (n / 10 == 0)
		ft_putchar(n % 10 + 48);
	if (n / 10 > 0)
	{
		ft_print_num(n / 10);
		ft_putchar(n % 10 + 48);
	}
}

int			ft_prime(int n)
{
	int 	i;

	i = 2;
	while (i < n)
		{
			if (n % i == 0)
				return (1);
			else
				i++;
		}
	return (0);
}

int			ft_prime_sum(int n)
{
	int		i;
	int		sum;

	i = 2;
	sum = 0;
	while (i <= n)
	{
		if (ft_prime(i) == 0)	
			sum = sum + i;
		i++;
	}
	return (sum);
}

int			ft_atoi(char *str)
{
	int		n;
	int		i;

	i= 0;
	n = 0;
	while (str[i] != '\0')
	{
		n = n * 10 + str[i] - 48; 
		i++;
	}
	return (n);
}

int			main(int argc, char **argv)
{
	if (argc != 2 || ft_atoi(argv[1]) <= 0)
	{
		write(1, "0\n", 2);
		return (1);
	}
	else
	{
		ft_print_num(ft_prime_sum(ft_atoi(argv[1])));
		ft_putchar('\n');
	}
	return (0);
}
