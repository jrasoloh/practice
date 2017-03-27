//
//  ft_operators.c
//  
//
//  Created by Jossy Ras on 26/03/2017.
//
//

#include "rpn_calc.h"

void                ft_add_op(op_list *begin_list, char element)
{
    op_list         *follower;
    
    follower = NULL;
    follower = malloc(sizeof(op_list) * 1);
    follower->data = element;
    follower->next = NULL;
    if (begin_list->next == NULL)
        begin_list-> next = follower;
    else
    {
        while (begin_list->next != NULL)
            begin_list = begin_list->next;
        begin_list->next = follower;
    }
}

int                 ft_count_op(op_list *begin_list)
{
    int             i;
    
    i = 0;
    while (begin_list != NULL)
    {
        i++;
        begin_list = begin_list->next;
    }
    return (i);
}


op_list			*ft_make_op_list(char *str)
{
	op_list		*begin_list;
	int			i;

	begin_list = NULL;
	begin_list = malloc(sizeof(op_list) * 1);
	begin_list->data = 0;
	begin_list->next = NULL;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '%')
		{
			if (begin_list->data == 0)
				begin_list->data = str[i];
			else
				ft_add_op(begin_list, str[i]);
			i++;
		}
		else
			i++;
	}
	return (begin_list);
}
