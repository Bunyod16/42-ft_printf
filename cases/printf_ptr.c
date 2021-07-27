#include "../ft_printf.h"
#include <stdio.h>
#include <stdint.h>

char *ft_rev(char *str)
{
	int len;
	char *ret;
	int i;

	len = ft_strlen(str) - 1;
	ret = malloc(len + 2);
	i = 0;
	while (len >= 0)
	{
		ret[i] = str[len];
		i++;
		len--;
	}
	ret[i] = 0;
	return (ret);
}

char	*to_hex(unsigned long long num)
{
	char ret[1024];
	int i;

	i = 0;
	while (num > 0)
	{
		ret[i] = (num % 16) + 48;
		if (((num % 16) + 48) > 57)
			ret[i] = (num % 16) + 87;
		num = num / 16;
		i++;
	}
	ret[i] = 0;
	return (ft_rev(ret));
}

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