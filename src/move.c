#include "ft_select.h"

int		move_r(t_select *data)
{
	t_tree	*tmp;

	while ()
}

int		move(t_select *data, int key)
{
	if (key == RIGHT)
		return (move_r(data));
	else if (key == LEFT)
		return (move_l(data));
	else if (key == UP)
		return (move_u(data));
	else if (key == DOWN)
		return (move_d(data));
	return (0);
}
