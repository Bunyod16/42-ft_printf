#include "../ft_printf.h"

void	printf_char(obj *flags)
{
	int c;
	
	c = va_arg(flags->args, int);
	flags->count += 1;
	write(0, &c, 1);
}