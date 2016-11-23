#include "ft_select.h"

static int	ret_init(t_select *data, char *str)
{
	close(data->fd);
	free_all(data);
	ft_printf("%s", str);
	return (1);
}

int		init_term(t_select *data)
{
	struct termios	term;
	char		*str_1;

	tcgetattr(data->fd, &term);
	term.c_lflag ^= (ECHO | ICANON);
	if (tcsetattr(data->fd, TCSANOW, &term) == -1)
		return (ret_init(data, "Error tcsetattr\n"));
	if (!(str_1 = getenv("TERM")))
		return (ret_init(data, "TERM variable not set correctly\n"));
	if (tgetent(NULL, str_1) != 1)
		return (ret_init(data, "Error tgetent\n"));
	return (0);
}
