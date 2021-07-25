#include "../ft_printf.h"

void    process_str(obj *flags)
{
    if (!flags->wdt && !flags->dash)
		printf_str(flags);
}