#include "../ft_printf.h"

void    process_x(obj *flags, char c)
{
    if (!flags->wdt && !flags->dash && c == 'x')
		printf_xl(flags);
	if (!flags->wdt && !flags->dash && c == 'X')
		printf_xu(flags);
}