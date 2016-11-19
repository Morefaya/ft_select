#include "ft_select.h"

int	putit(int c)
{
	static int	fd = -1;

	if (fd == -1)
		fd = open("/dev/tty", O_WRONLY);
	ft_putchar_fd(c, fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_tree	*e_tree;

	if (!(e_tree = get_arg(ac, av)))
		return (1);
	//print_arg(e_tree);
	print_select(e_tree);
	ft_trdel(&e_tree, (void(*)(void*, size_t))del_elem);
	/*char	*str_1;
	char	*str_2;
	char	*line;
	int	ret;
	struct termios	term;

	tcgetattr(0, &term);
	ft_printf("%d\t%d\n", term.c_cc[VMIN], term.c_cc[VTIME]);
	term.c_lflag ^= (ICANON);
	//ft_printf("%d\n", term.c_lflag);
	tcsetattr(0, TCSANOW, &term);
	//term.c_lflag &= ~(ICANON | ECHO);
	str_1 = getenv("TERM");
	str_2 = NULL;
	line = NULL;
	ret = tgetent(str_2, str_1);
	//tputs(tgetstr("cl", NULL), 1, putit);
	ft_printf("21_sh$> ");
	while (get_next_line(0, &line) > 0)
	{
		ft_printf("%s\n", line);
		ft_printf("21_sh$> ");
		free(line);
	}
	free(line);
	free(str_2);*/
	//while (42);
	return (0);
}
