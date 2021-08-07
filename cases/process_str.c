#include "../ft_printf.h"

static void	count_space_prc(t_obj *flags, int *space, char *str)
{
	*space = 0;
	if (!flags->prc && flags->pnt)
		flags->prc = 0;
	else if (!flags->prc || flags->prc > (int) ft_strlen(str))
		flags->prc = ft_strlen(str);
	if (flags->wdt > flags->prc)
		*space = flags->wdt - flags->prc;
}

void	process_str(t_obj *flags)
{
	const char	*str = va_arg(flags->args, char *);
	int			space;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		flags->count += 6;
		return ;
	}
	count_space_prc(flags, &space, (char *) str);
	if (flags->dash)
	{
		write(1, str, flags->prc);
		ft_putnchar_fd(' ', space, 1);
	}
	else
	{
		ft_putnchar_fd(' ', space, 1);
		write(1, str, flags->prc);
	}
	flags->count += flags->prc + space;
}
