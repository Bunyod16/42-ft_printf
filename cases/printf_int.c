#include "../ft_printf.h"

void	printf_int(obj* flags)
{
	int num;
	
	num = va_arg(flags->args, int);
	ft_putnbr_fd(num, 1);
}