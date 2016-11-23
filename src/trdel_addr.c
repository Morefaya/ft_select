/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trdel_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:10:08 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/23 16:10:11 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	trdel_addr(t_tree **lst, t_tree *link, void (*del)(void*, size_t))
{
	t_tree	*tmp_1;
	t_tree	*tmp_2;

	if (!lst || !*lst || !link || !del)
		return ;
	tmp_1 = *lst;
	if (*lst == link)
	{
		*lst = (*lst)->right;
		ft_trdelone(&tmp_1, del);
		return ;
	}
	while (tmp_1->right && tmp_1->right != link)
		tmp_1 = tmp_1->right;
	if (!tmp_1->right)
		return ;
	tmp_2 = tmp_1->right;
	tmp_1->right = tmp_1->right->right;
	ft_trdelone(&tmp_2, del);
}
