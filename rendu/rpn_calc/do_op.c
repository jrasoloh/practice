//
//  do_op.c
//  
//
//  Created by Jossy Ras on 26/03/2017.
//
//

#include "rpn_calc.h"

int             ft_do_op(int a, int b, char c)
{
    if (c == '+')
        return (a + b);
    else
    {
        if (c == '-')
            return (a - b);
        else
        {
            if (c == '*')
                return (a * b);
            else
            {
                if (c == '/')
                    return (a / b);
                else
                    return (a % b);
            }
        }
    }
    return (0);
}
