#include "../ft_printf.h"

static void	count_space_prc(t_obj *flags, char *num)
{
	int len;
	int abs_len;

	len = (int) ft_strlen(num);
	abs_len =  (int) ft_strlen(num);
	if (num[0] == '-')
		abs_len -= 1;
	if (abs_len >= flags->prc)
		flags->prc = 0;
	if (flags->prc > abs_len)
		flags->prc = flags->prc - abs_len;
	if (flags->wdt)
		flags->wdt = flags->wdt - len - flags->prc;
}

void	process_ndec(t_obj *flags, char *s_num)
{
	if (flags->dash)
	{
		ft_putchar_fd('-', 1);
		ft_putnchar_fd('0', flags->prc, 1);
		ft_putstr_fd(&s_num[1], 1);
		ft_putnchar_fd(' ', flags->wdt, 1);
	}
	else if (!flags->dash)
	{
		ft_putnchar_fd(' ', flags->wdt, 1);
		ft_putchar_fd('-', 1);
		ft_putnchar_fd('0', flags->prc, 1);
		ft_putstr_fd(&s_num[1], 1);
	}
	flags->count += ft_strlen(&s_num[1]) + flags->wdt + flags->prc + 1;
}

void	process_dec(t_obj *flags)
{
	int		num;
	char	*s_num;

	num = va_arg(flags->args, int);
	s_num = ft_itoa(num);
	count_space_prc(flags, s_num);
	if (num < 0)
		process_ndec(flags, s_num);
	else
	{
		if (flags->dash)
		{

			ft_putnchar_fd('0', flags->prc, 1);
			ft_putstr_fd(s_num, 1);
			ft_putnchar_fd(' ', flags->wdt, 1);
		}
		else if (!flags->dash)
		{
			ft_putnchar_fd(' ', flags->wdt, 1);
			ft_putnchar_fd('0', flags->prc, 1);
			ft_putstr_fd(s_num, 1);
		}
		flags->count += ft_strlen(s_num) + flags->wdt + flags->prc;
	}
	free(s_num);
}
