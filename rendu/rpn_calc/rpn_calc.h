//
//  rpn_calc.h
//  
//
//  Created by Jossy Ras on 26/03/2017.
//
//

#ifndef RPN_CALC__H
# define RPN_CALC__H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct          i_list
{
    struct i_list       *next;
    int                 data;
}                       int_list;

typedef struct          o_list
{
    struct o_list       *next;
    char                data;
}                       op_list;

void                    ft_add_nb(int_list *begin_list, int element);
void                    ft_add_op(op_list *begin_list, char element);
int                     ft_count_nb(int_list *begin_list);
int                     ft_count_op(op_list *begin_list);
int                     ft_do_op(int a, int b, char c);
int                     ft_rpn_calc(int_list *nb, op_list *op);
int_list				*ft_make_nb_list(char *str);
op_list					*ft_make_op_list(char *str);

#endif
