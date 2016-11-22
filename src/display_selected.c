#include "ft_select.h"

int	display_selected(t_select *data)
{
	t_tree	*tree;
	int	i;

	tree = data->tree;
	i = 0;
	while (tree)
	{
		if (i && SELECT(tree))
			ft_putchar_fd(' ', data->fd);
		if (SELECT(tree))
		{
			ft_putstr_fd(NAME(tree), data->fd);
			i++;
		}
		tree = tree->right;
		if (!tree && i)
			ft_putchar_fd('\n', data->fd);
	}
	return (1);
}
