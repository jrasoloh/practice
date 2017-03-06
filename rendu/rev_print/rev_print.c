#include <unistd.h>

int			ft_length(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int 		main(int argc, char **argv)
{
	int		i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	else
	{
		i = ft_length(argv[1]) - 1;
		while (i >= 0)
		{
			write(1, &argv[1][i], 1);
			i--;
		}
		write(1, "\n", 1);
	}
	return (0);
}
