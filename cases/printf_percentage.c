#include "../ft_printf.h"

void	printf_percentage(obj *flags)
{
	ft_putstr_fd("%", 1);
	flags->count += 1;
}