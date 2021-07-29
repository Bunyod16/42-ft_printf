#include "../ft_printf.h"

void	printf_char(obj *flags)
{
	int c;
	
	c = va_arg(flags->args, int);
	flags->count += 1;
	write(1, &c, 1);
}

void    printf_char_wdt(obj *flags)
{
	int c;
	int wdt;
    wdt = flags->wdt;
    while(wdt-- > 1)
    {
		flags->count += 1;
        ft_putchar_fd(' ', 1);
    }
	c = va_arg(flags->args, int);
	flags->count += 1;
	ft_putchar_fd(c, 1);
}

void printf_char_wdt_dash(obj *flags)
{
    int c;
	int wdt;
    
    wdt = flags->wdt;
    c = va_arg(flags->args, int);
    ft_putchar_fd(c, 1);
    flags->count += 1;  
    while(wdt-- > 1)
    {
        ft_putchar_fd(' ', 1);
        flags->count += 1;
    }
}