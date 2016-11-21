#ifndef TEST_H
# define TEST_H

# include "libft.h"
# include "ft_printf.h"
# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>

# define NAME(x) ((t_elem*)(x->content))->name
# define CUR(x) ((t_elem*)(x->content))->cur

# define ESC 	0x1b
# define RET 	0xa
# define RIGHT 	0x435b1b
# define LEFT 	0x445b1b
# define UP 	0x415b1b
# define DOWN 	0x425b1b
# define DEL_1 	0x7f
# define DEL_2 	0x7e335b1b
# define CTL_D 	0x4

typedef struct	s_elem
{
	char		*name;
	int			cur;
	int			select;
}				t_elem;

typedef struct	s_select
{
	t_tree		*tree;
	int			fd;
	t_list		*pos;
}				t_select;

t_tree			*get_arg(int ac, char **av);
void			print_arg(t_tree *tree);
void			del_elem(t_elem *tree, size_t ct);
void			print_select(t_select *tree);

#endif
