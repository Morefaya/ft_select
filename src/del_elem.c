#include "ft_select.h"

void	del_elem(t_elem *el, size_t ct)
{
	ft_bzero(el, ct);
	free(el);
}
