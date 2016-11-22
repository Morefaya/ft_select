#include "ft_select.h"

static void	move_d(t_select *data, int nb_col)
{
	int	i;

	i = 0;
	while (i++ < nb_col)
		ft_lstrotate(&data->pos);
}

static void	move_u(t_select *data, int nb_col)
{
	int	i;

	i = 0;
	while (i++ < nb_col)
		ft_lstrev_rotate(&data->pos);
}

static int	get_nb_col(t_select *data)
{
	struct winsize	ws;
	int		largest;

	if ((ioctl(data->fd, TIOCGWINSZ, &ws) == -1))
	{
		ft_putendl_fd("Error ioctl", data->fd);
		return (0);
	}
	largest = get_largest(data->tree);
	largest += (8 - largest % 8);
	return (ws.ws_col / largest);
}

int		move(t_select *data, int key)
{
	int	nb_col;

	nb_col = get_nb_col(data);
	if (key == RIGHT)
		ft_lstrotate(&data->pos);
	else if (key == LEFT)
		ft_lstrev_rotate(&data->pos);
	else if (key == UP)
		move_u(data, nb_col);
	else if (key == DOWN)
		move_d(data, nb_col);
	return (0);
}
