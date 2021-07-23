#include "../libftprintf.h"

void	printf_percentage(obj *flags)
{
	ft_putstr_fd("%",0);
	flags->count += 1;
}