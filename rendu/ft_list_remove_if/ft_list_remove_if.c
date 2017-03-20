#include "ft_list.h"
#include <stdlib.h>

void		ft_list_remove_if(t_list **begin_list, void *data_ref, int	(*cmp)())
{
	t_list	*tmp;

	tmp = NULL;	
	while ((*begin_list) != NULL)
	{
		if (cmp(data_ref, ((*begin_list)->data)) == 0)
		{
			free(*begin_list);
			(*begin_list) = NULL;
			(*begin_list)->data = NULL;
			tmp->next = (*begin_list)->next;
		}
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
	}
}
