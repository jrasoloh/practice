#ifndef		FT_LIST_SIZE__H
# define	FT_LIST_SIZE__H

# include <unistd.h>
# include <stdlib.h>

typedef	struct			s_list
{
		struct s_list	*next;
		void			*data;
}						t_list;

int						ft_list_size(t_list *begin_list);

#endif
