#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



int			main(int argc, char **argv)
{
	
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	else
		rpn_calc(argv[1]);
	return (0);
}

