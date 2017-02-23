/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcazako <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:11:20 by jcazako           #+#    #+#             */
/*   Updated: 2016/11/23 16:11:22 by jcazako          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	resize(int c)
{
	t_select	*data;

	data = ret_tree();
	(void)c;
	tputs(tgetstr("cl", NULL), data->fd, putit);
	print_select(data);
}

void	ctl_z(int c)
{
	t_select		*data;
	struct termios	term;
	char			chr[2];

	(void)c;
	data = ret_tree();
	if (!isatty(data->fd))
		return ;
	tcgetattr(data->fd, &term);
	ft_bzero(chr, 2);
	chr[0] = term.c_cc[VSUSP];
	tputs(tgetstr("te", NULL), data->fd, putit);
	tputs(tgetstr("ve", NULL), data->fd, putit);
	signal(SIGTSTP, SIG_DFL);
	ioctl(data->fd, TIOCSTI, chr);
}

void	fg_bg(int c)
{
	t_select		*data;
	struct termios	term;

	(void)c;
	data = ret_tree();
	tcgetattr(data->fd, &term);
	term.c_lflag ^= (ECHO | ICANON);
	tcsetattr(data->fd, TCSANOW, &term);
	signal(SIGTSTP, ctl_z);
	tputs(tgetstr("ti", NULL), data->fd, putit);
	tputs(tgetstr("vi", NULL), data->fd, putit);
	tputs(tgetstr("ho", NULL), data->fd, putit);
	print_select(data);
}

void	ctl_c(int c)
{
	t_select		*data;
	struct termios	term;

	(void)c;
	data = ret_tree();
	if (!isatty(data->fd))
		return ;
	tcgetattr(data->fd, &term);
	term.c_lflag ^= (ECHO | ICANON);
	tcsetattr(data->fd, TCSANOW, &term);
	tputs(tgetstr("te", NULL), data->fd, putit);
	tputs(tgetstr("ve", NULL), data->fd, putit);
	exit(0);
}
