#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *str, ...);

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
	int zero;
	int	sp;
}	obj;

void	printf_percentage(obj *flags);
void	printf_char(obj *flags);
# endif