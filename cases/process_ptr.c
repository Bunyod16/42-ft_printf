#include "../ft_printf.h"

void    process_ptr(obj *flags)
{
    if (!flags->wdt && !flags->dash)
		printf_ptr(flags);
}