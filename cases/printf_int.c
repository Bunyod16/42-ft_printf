#include "../ft_printf.h"

void	printf_int(obj* flags)
{
	int num;;

	num = va_arg(flags->args, int);
	ft_putnbr_fd(num, 1);
	flags->count += 1;
	if (num < 0)
		flags->count += 1;
	while (num >= 10 || num <= -10)
	{
		num /= 10;
		flags->count += 1;
	}
}