//
//  rpn_calc.c
//  
//
//  Created by Jossy Ras on 25/03/2017.
//
//

#include "rpn_calc.h"

int                 ft_rpn_calc(int_list *nb, op_list *op)
{
    int             res;
    
    res = nb->data;
    if (nb->next != NULL)
    {
        nb = nb->next;
        while (nb)
        {
            res = ft_do_op(res, nb->data, op->data);
            nb = nb->next;
            op = op->next;
        }
    }
    return (res);
    
}
int                 main(int argc, char **argv)
{
    int_list        *numbers;
    op_list         *operator;
    int             nb;
    int             op;
    
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		numbers = ft_make_nb_list(argv[1]);
		operator = ft_make_op_list(argv[1]);
    	nb = ft_count_nb(numbers);
    	op = ft_count_op(operator);
		if (nb - op != 1)
		{
			printf("Error\n");
			return (1);
		}
		else
    		printf("%d\n", ft_rpn_calc(numbers, operator));
	}
	return (0);
}

