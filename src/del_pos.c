#include "ft_select.h"

void	del_pos(t_pos *pos, size_t ct)
{	
	ft_bzero(pos, ct);
	free(pos);
}
