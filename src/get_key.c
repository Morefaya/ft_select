#include "ft_select.h"

static int	selected(t_select *data)
{
	t_tree	*tree;

	tree = POS(data->pos);
	SELECT(tree) = (SELECT(tree)) ? 0 : 1;
	ft_lstrotate(&data->pos);
	return (0);
}

static int	del_cur(t_select *data)
{
	trdel_addr(&data->tree, POS(data->pos),
		(void(*)(void*, size_t))del_elem);
	ft_lstdel_range(&data->pos, 1, (void(*)(void*, size_t))del_pos);
	if (data->tree && data->pos)
		return (0);
	else
	{
		tputs(tgetstr("te", NULL), data->fd, putit);
		tputs(tgetstr("ve", NULL), data->fd, putit);
		free_all(data);
		exit(0);
	}
}

int	get_key(t_select *data)
{
	char	buff[4];
	int		key;
	int		ret;

	ret = 0;
	(void)data;
	ft_bzero(buff, 4);
	read(data->fd, buff, 4);
	key = *((int*)buff);
	if (key == ESC || key == CTL_D)
	{
		tputs(tgetstr("te", NULL), data->fd, putit);
		tputs(tgetstr("ve", NULL), data->fd, putit);
		free_all(data);
		exit(0);
	}	
	else if (key == RIGHT || key == LEFT || key == UP || key == DOWN)
		return (move(data, key));
	else if (key == SPACE)
		return (selected(data));
	else if (key == RET)
		return (1);
	else if (key == DEL_1 || key == DEL_2)
		return (del_cur(data));
	return (0);
}
