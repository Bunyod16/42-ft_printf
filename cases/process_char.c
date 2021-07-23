#include "../ft_printf.h"

void    process_char(obj *flags)
{
    if (!flags->wdt && !flags->dash)
		printf_char(flags);
	else if (flags->wdt && !flags->dash)
        printf_char_wdt(flags);
    else if (flags->wdt && flags->dash)
        printf_char_wdt_dash(flags);
}