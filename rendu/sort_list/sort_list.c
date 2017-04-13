#include "list.h"

t_list			*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int			min;

	min = lst->data;
	while (lst->next != NULL && ft_sorted(lst, cmp) == 1)
	{
		if ((*cmp)(lst->next->data, min) == 0)
			min = lst->next->data;
	}
}
