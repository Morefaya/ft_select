#include "ft_select.h"

int	get_largest(t_tree *tree)
{
	int	large;
	int	len;

	large = 0;
	len = 0;
	while (tree)
	{
		len = ft_strlen(NAME(tree));
		large = (len > large) ? len : large;
		tree = tree->right;
	}
	return (large);
}

void	print_col(t_tree *tree, int len, int nb_col)
{
	int	tmp;
	int	i;

	i = 1;
	while (tree)
	{
		tmp = ft_strlen(NAME(tree));
		ft_printf("%s", NAME(tree));
		tmp = tmp + 8 - tmp % 8;
		while (tmp <= len)
		{
			ft_putchar('\t');
			tmp += 8;
		}
		tree = tree->right;
		if (!(i % nb_col))
			ft_putchar('\n');
		i++;
	}
}

void	print_select(t_tree *tree)
{
	int	large;

	large = get_largest(tree);
	large = large + 8 - large % 8;
	ft_printf("large: %d\n", large);
	print_col(tree, large, 3);
}
