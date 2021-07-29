#include "../ft_printf.h"
#include <stdio.h>
#include <stdint.h>

void	printf_ptr_nil(obj *flags)
{
	flags->count += 5;
	ft_putstr_fd("(nil)", 1);
	return ;
}

void	printf_ptr(obj* flags)
{
	long long	num;
	char		*str;
	char		*prefix;
	unsigned long long neg_num; 

	prefix = "0x";
	num = (long long) va_arg(flags->args, void *);
	if (num == 0)
	{
		printf_ptr_nil(flags);
		return ;
	}
	if (num < 0)
	{
		neg_num = 18446744073709551615U + num + 1;
		str = to_hex(neg_num);
	}
	else
		str = to_hex(num);
	ft_putstr_fd(prefix, 1);
	ft_putstr_fd(str, 1);
	flags->count += ft_strlen(str) + 2;
	free(str);
}