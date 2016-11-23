/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:08:25 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/23 16:08:27 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_arg(t_tree *tree)
{
	while (tree)
	{
		ft_printf("%s\t", ((t_elem*)(tree->content))->name);
		tree = tree->right;
	}
	ft_putchar('\n');
}
