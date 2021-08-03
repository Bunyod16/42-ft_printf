#include "../ft_printf.h"
#include <stdint.h>

void	printf_ptr_nil(t_obj *flags)
{
	flags->count += 5;
	ft_putstr_fd("(nil)", 1);
	return ;
}

void	count_space(t_obj *flags, int *space, int strlen)
{
	*space = 0;
	if (flags->wdt > strlen)
	{
		*space = flags->wdt - strlen;
		flags->count += flags->wdt;
	}
	else
		flags->count += strlen;
}

void	process_ptr(t_obj *flags)
{
	long long	num;
	char		*str;
	int			space;

	num = (long long) va_arg(flags->args, void *);
	if (num == 0)
		printf_ptr_nil(flags);
	else
	{
		if (num < 0)
			str = to_hex(18446744073709551615U + num + 1);
		else
			str = to_hex(num);
		count_space(flags, &space, ft_strlen(str) + 2);
		if (!flags->dash)
			ft_putnchar_fd(' ', space, 1);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(str, 1);
		if (flags->dash)
			ft_putnchar_fd(' ', space, 1);
		free(str);
	}
}
