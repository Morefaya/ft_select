#ifndef TEST_H
# define TEST_H

# include "libft.h"
# include "ft_printf.h"
# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>

# define NAME(x) ((t_elem*)(x->content))->name

#define ESC 0x1b

typedef struct	s_elem
{
	char	*name;
	int	cur;
	int	select;
}		t_elem;

typedef struct	s_select
{
	t_tree	*tree;
	int	fd;
}		t_select;

t_tree	*get_arg(int ac, char **av);
void	print_arg(t_tree *tree);
void	del_elem(t_elem *tree, size_t ct);
void	print_select(t_select *tree);

#endif
