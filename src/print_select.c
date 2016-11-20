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

static void	print_col(t_tree *tree, int len, int nb_col)
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

static int	check_term_size(struct winsize ws, t_tree *tree, int large)
{
	int	len;
	int	tot;
	int	term_s;

	len = 0;
	term_s = ws.ws_col * (ws.ws_row - 1);
	while (tree)
	{
		tree = tree->right;
		len++;
	}
	tot = len * large;
	if (tot > term_s || ws.ws_col < large)
		return (1);
	else
		return (0);
}

void	print_select(t_tree *tree)
{
	int		large;
	struct winsize	ws;

	if ((ioctl(1, TIOCGWINSZ, &ws) == -1))
	{
		ft_printf("error ioctl\n");
		return ;
	}
	large = get_largest(tree);
	large = large + 8 - large % 8;
	if (check_term_size(ws, tree, large))
	{
		ft_printf("window too small\n");
		return ;
	}
	print_col(tree, large, ws.ws_col / large);
}
