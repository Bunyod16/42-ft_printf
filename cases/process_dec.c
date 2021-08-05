#include "../ft_printf.h"
#include <stdio.h>

static void	count_space_prc(t_obj *flags, char *num)
{
	int	abs_len;
	int	len;

	len = (int) ft_strlen(num);
	abs_len =  (int) ft_strlen(num);
	if (num[0] == '-')
		abs_len -= 1;
	if (abs_len >= flags->prc)
		flags->prc = 0;
	if (flags->prc > abs_len)
		flags->prc = flags->prc - abs_len;
	if (flags->wdt <= 0 || (flags->dash && flags->wdt <= abs_len))
		flags->wdt = 0;
	if (flags->wdt)
		flags->wdt = flags->wdt - len - flags->prc;
	if (flags->wdt <= 0)
		flags->wdt = 0;
	if (flags->prc <= 0)
		flags->prc = 0;
}

static void	process_ndec(t_obj *flags, char *s_num)
{
	if (flags->zero)
	{
		ft_putchar_fd('-', 1);
		ft_putnchar_fd('0', flags->wdt, 1);
		ft_putstr_fd(&s_num[1], 1);
	}
	else
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
	}
	flags->count += ft_strlen(&s_num[1]) + flags->wdt + flags->prc + 1;
}

static void	process_pdec(t_obj *flags, char *s_num)
{
	if (flags->sp)
		ft_putchar_fd(' ', 1);
	if (flags->sign)
		ft_putchar_fd('+', 1);
	if (flags->zero)
	{
		ft_putnchar_fd('0', flags->wdt, 1);
		ft_putstr_fd(&s_num[0], 1);
	}
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
	}
	flags->count += ft_strlen(&s_num[0]) + flags->wdt + flags->prc +
	+ flags->sign + flags->sp;
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
		process_pdec(flags, s_num);
	free(s_num);
}
