#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *str, ...);
#include <stdarg.h>
#include "libft.h"

typedef struct a_struct
{
	va_list	args;
	int	wdt;
	int	prc;
	int zero;
	int	pnt;
	int	dash;
	int tl;
	int sign;
	int	is_zero;
	int	perc;
	int	sp;
}	obj;
# endif