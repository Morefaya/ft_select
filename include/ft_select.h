/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:57:00 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/23 15:59:48 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "libft.h"
# include "ft_printf.h"
# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>

# define NAME(x) ((t_elem*)(x->content))->name
# define POS(x) ((t_pos*)(x->content))->tree
# define SELECT(x) ((t_elem*)(x->content))->select

# define NORM "\x1B[0m"
# define BOLD "\033[1m"

# define ESC 	0x1b
# define RET 	0xa
# define SPACE	0x20
# define RIGHT 	0x435b1b
# define LEFT 	0x445b1b
# define UP 	0x415b1b
# define DOWN 	0x425b1b
# define DEL_1 	0x7f
# define DEL_2 	0x7e335b1b
# define CTL_D 	0x4

typedef struct	s_pos
{
	t_tree		*tree;
}				t_pos;

typedef struct	s_elem
{
	char		*name;
	int			select;
}				t_elem;

typedef struct termios	t_term;

typedef struct	s_select
{
	t_tree		*tree;
	int			fd;
	t_list		*pos;
}				t_select;

t_tree			*get_arg(int ac, char **av);
void			print_arg(t_tree *tree);
void			del_elem(t_elem *tree, size_t ct);
void			del_select(t_select *data, size_t ct);
void			del_pos(t_pos *pos_lst, size_t ct);
void			print_select(t_select *tree);
t_list			*get_pos_lst(t_tree *tree);
int				putit(int c);
int				move(t_select *data, int key);
int				get_largest(t_tree *tree);
int				get_key(t_select *data);
int				display_selected(t_select *data);
void			free_all(t_select *data);
void			trdel_addr(t_tree **tree, t_tree *link,
	void (*del)(void*, size_t));
int				init_term(t_select *data);
void			resize(int c);
void			ctl_z(int c);
void			fg_bg(int c);
void			ctl_c(int c);
t_select		*ret_tree(void);


#endif
