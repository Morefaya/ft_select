/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:05:11 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/23 16:05:13 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_list	*get_pos_lst(t_tree *tree)
{
	t_list	*pos_lst;
	t_list	*tmp;
	t_pos	content;

	pos_lst = NULL;
	while (tree)
	{
		content.tree = tree;
		if (!(tmp = ft_lstnew(&content, sizeof(content))))
		{
			ft_lstdel(&pos_lst, (void(*)(void*, size_t))del_pos);
			return (NULL);
		}
		if (!pos_lst)
			ft_lstadd(&pos_lst, tmp);
		else
			ft_lstadd_back(pos_lst, tmp);
		tree = tree->right;
	}
	return (pos_lst);
}
