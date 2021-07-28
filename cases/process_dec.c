#include "../ft_printf.h"

void    process_dec(obj *flags)
{
    if (!flags->wdt && !flags->dash)
		printf_dec(flags);
}