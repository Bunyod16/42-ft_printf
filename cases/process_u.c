#include "../ft_printf.h"

void    process_u(obj *flags)
{
    if (!flags->wdt && !flags->dash)
		printf_u(flags);
}