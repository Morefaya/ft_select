/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:09:52 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/23 16:13:33 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_select	*ret_tree(void)
{
	static t_select	*data = NULL;

	if (!data)
	{
		if (!(data = (t_select*)malloc(sizeof(t_select))))
		{
			ft_printf("Error malloc\n");
			exit(2);
		}
	}
	return (data);
}

int			putit(int c)
{
	t_select	*data;

	data = ret_tree();
	ft_putchar_fd(c, data->fd);
	return (0);
}

static int	init_data(int ac, char **av, t_select *data)
{
	data->tree = NULL;
	data->fd = -1;
	data->pos = NULL;
	if (!(data->tree = get_arg(ac, av)))
		return (1);
	if ((data->fd = open("/dev/tty", O_RDWR)) == -1)
	{
		free_all(data);
		return (2);
	}
	if (!(data->pos = get_pos_lst(data->tree)))
	{
		close(data->fd);
		free_all(data);
		return (3);
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_select	*data;

	data = ret_tree();
	if (init_data(ac, av, data))
		return (1);
	if (init_term(data))
		return (2);
	tputs(tgetstr("ti", NULL), data->fd, putit);
	tputs(tgetstr("vi", NULL), data->fd, putit);
	signal(SIGWINCH, resize);
	signal(SIGTSTP, ctl_z);
	signal(SIGCONT, fg_bg);
	signal(SIGINT, ctl_c);
	while (42)
	{
		tputs(tgetstr("cl", NULL), data->fd, putit);
		print_select(data);
		if (get_key(data))
			break ;
	}
	tputs(tgetstr("te", NULL), data->fd, putit);
	tputs(tgetstr("ve", NULL), data->fd, putit);
	display_selected(data);
	free_all(data);
	return (0);
}
