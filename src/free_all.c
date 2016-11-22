#include "ft_select.h"

void	free_all(t_select *data)
{
	close(data->fd);
	ft_trdel(&data->tree, (void(*)(void*, size_t))del_elem);
	ft_lstdel(&data->pos, (void(*)(void*, size_t))del_pos);
	free(data);
}
