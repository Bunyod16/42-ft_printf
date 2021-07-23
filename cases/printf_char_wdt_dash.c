#include "../ft_printf.h"

void printf_char_wdt_dash(obj *flags)
{
    int c;
	int wdt;
    
    wdt = flags->wdt;
    c = va_arg(flags->args, int);
    write(0, &c, 1);
    flags->count += 1;  
    while(wdt-- > 1)
    {
        ft_putchar_fd(' ', 0);
    }
}