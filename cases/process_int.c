#include "../ft_printf.h"

void    process_int(obj *flags)
{
    if (!flags->wdt && !flags->dash)
		printf_int(flags);
}