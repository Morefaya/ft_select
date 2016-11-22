#include "ft_select.h"

static void	tr_add_first(t_tree **a_tree, t_tree *new)
{
	new->right = *a_tree;
	*a_tree = new;
}

static void	tr_add(t_tree *tree, t_tree *new)
{
	if (!tree || !new)
		return ;
	while (tree->right)
		tree = tree->right;
	tree->right = new;
}

t_tree		*get_arg(int ac, char **av)
{
	t_tree	*e_tree;
	t_tree	*tmp;
	t_elem	content;
	int	i;

	e_tree = NULL;
	i = 1;
	while (i < ac)
	{
		content.name = av[i];
		content.select = 0;
		if (!(tmp = ft_trnew(&content, sizeof(content))))
		{
			ft_trdel(&e_tree, (void(*)(void*, size_t))del_elem);
			return (NULL);
		}
		if (!e_tree)
			tr_add_first(&e_tree, tmp);
		else
			tr_add(e_tree, tmp);
		i++;
	}
	return (e_tree);
}
