#include "ft_select.h"

void	print_arg(t_tree *tree)
{
	while (tree)
	{
		ft_printf("%s\t", ((t_elem*)(tree->content))->name);
		tree = tree->right;
	}
	ft_putchar('\n');
}
