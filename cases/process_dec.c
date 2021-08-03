#include "../ft_printf.h"

static void	count_space_prc(t_obj *flags, int *space, char* num)
{
	int len;

	*space = 0;
	len = 1;
	if (flags->wdt || flags->prc)
	{
		flags->prc = flags->prc - ft_strlen(num);
		*space = flags->wdt - len - flags->prc;
	}
}

void	process_ndec(t_obj *flags, char *s_num, int space)

void	process_dec(t_obj *flags)
{
	int	num;
	int space;
	char *s_num;

	num = va_arg(flags->args, int);
	s_num = ft_itoa(num);
	count_space_prc(flags, &space, s_num);
	if (num < 0)
		process_ndec(flags, s_num, space);
	else
	{
		if (flags->dash)
		{

			ft_putnchar_fd('0', flags->prc, 1);
			ft_putstr_fd(s_num, 1);

		}
		else if (!flags->dash)
		{
			ft_putnchar_fd(' ', space, 1);
			ft_putnchar_fd('0', flags->prc, 1);
			ft_putstr_fd(s_num, 1);
		}
		flags->count += ft_strlen(s_num) + space + flags->prc;
	}
}
