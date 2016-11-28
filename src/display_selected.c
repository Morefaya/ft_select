/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_selected.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:04:57 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/23 16:04:58 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	display_selected(t_select *data)
{
	t_tree	*tree;
	int		i;

	tree = data->tree;
	i = 0;
	while (tree)
	{
		if (i && SELECT(tree))
			ft_putchar_fd(' ', 1);
		if (SELECT(tree))
		{
			ft_putstr_fd(NAME(tree), 1);
			i++;
		}
		tree = tree->right;
		if (!tree && i)
			ft_putchar_fd('\n', 1);
	}
	return (1);
}
