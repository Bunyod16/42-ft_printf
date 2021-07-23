#include "../libftprintf.h"

void    printf_char_wdt(obj *flags)
{
	int c;
	int wdt;
    
    wdt = flags->wdt;
    while(wdt-- > 1)
    {
        ft_putchar_fd(' ', 0);
    }
	c = va_arg(flags->args, int);
	flags->count += 1;
	write(0, &c, 1);    
}