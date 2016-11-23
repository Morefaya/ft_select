/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_select.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:12:21 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/23 16:23:26 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			get_largest(t_tree *tree)
{
	int	large;
	int	len;

	large = 0;
	len = 0;
	while (tree)
	{
		len = ft_strlen(NAME(tree));
		large = (len > large) ? len : large;
		tree = tree->right;
	}
	return (large);
}

static void	disp_col(t_select *data, t_tree *tree)
{
	if (tree == POS(data->pos))
	{
		ft_putstr_fd(BOLD, data->fd);
		tputs(tgetstr("us", NULL), data->fd, putit);
	}
	if (SELECT(tree))
		tputs(tgetstr("mr", NULL), data->fd, putit);
	ft_putstr_fd(NAME(tree), data->fd);
	ft_putstr_fd(NORM, data->fd);
	tputs(tgetstr("ue", NULL), data->fd, putit);
	tputs(tgetstr("me", NULL), data->fd, putit);
}

static void	print_col(t_select *data, short ws_col, int len)
{
	int		tmp;
	int		i;
	t_tree	*tree;

	i = 1;
	tree = data->tree;
	while (tree)
	{
		tmp = ft_strlen(NAME(tree));
		tmp = tmp + 8 - tmp % 8;
		disp_col(data, tree);
		while (tmp <= len)
		{
			ft_putchar_fd('\t', data->fd);
			tmp += 8;
		}
		tree = tree->right;
		if (!(i % (ws_col / len)))
			ft_putchar_fd('\n', data->fd);
		i++;
	}
}

static int	check_term_size(struct winsize ws, t_tree *tree, int large)
{
	int	len;
	int	tot;
	int	term_s;

	len = 0;
	term_s = ws.ws_col * (ws.ws_row - 1);
	while (tree)
	{
		tree = tree->right;
		len++;
	}
	tot = len * large;
	if (tot > term_s || ws.ws_col < large)
		return (1);
	else
		return (0);
}

void		print_select(t_select *data)
{
	int				large;
	struct winsize	ws;

	if ((ioctl(data->fd, TIOCGWINSZ, &ws) == -1))
	{
		ft_putendl_fd("error ioctl", data->fd);
		return ;
	}
	large = get_largest(data->tree);
	large = large + 8 - large % 8;
	if (check_term_size(ws, data->tree, large))
	{
		ft_putendl_fd("window too small", data->fd);
		return ;
	}
	print_col(data, ws.ws_col, large);
}
