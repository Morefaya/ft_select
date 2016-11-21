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

static void	print_col(t_tree *tree, int len, int nb_col, int fd)
{
	int	tmp;
	int	i;

	i = 1;
	while (tree)
	{
		tmp = ft_strlen(NAME(tree));
		ft_putstr_fd(NAME(tree), fd);
		tmp = tmp + 8 - tmp % 8;
		while (tmp <= len)
		{
			ft_putchar_fd('\t', fd);
			tmp += 8;
		}
		tree = tree->right;
		if (!(i % nb_col))
			ft_putchar_fd('\n', fd);
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

void	print_select(t_select *data)
{
	int		large;
	struct winsize	ws;

	if ((ioctl(data->fd, TIOCGWINSZ, &ws) == -1))
	{
		ft_putendl_fd("error ioctl", data->fd);
		return ;
	}
	large = get_largest(data->tree);
	large = large + 8 - large % 8;
	if (check_term_size(ws, data->tree, large))
	{
		ft_putendl_fd("window too small", data->fd);
		return ;
	}
	print_col(data->tree, large, ws.ws_col / large, data->fd);
}
