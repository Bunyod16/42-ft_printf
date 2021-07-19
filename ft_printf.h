#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *str, ...);
#include <stdarg.h>
#include "libft.h"

typedef struct a_struct
{
	va_list	args;
	int sign;
	int	prc;
	int	pnt;
	int	dash;
	int count;
	int	wdt;
	int	is_zero;
	int	perc;
	int zero;
	int	sp;
}	obj;

void	printf_percentage(obj *flags);
# endif