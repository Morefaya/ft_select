/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:04:43 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/23 16:04:44 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	free_all(t_select *data)
{
	close(data->fd);
	ft_trdel(&data->tree, (void(*)(void*, size_t))del_elem);
	ft_lstdel(&data->pos, (void(*)(void*, size_t))del_pos);
	free(data);
}
