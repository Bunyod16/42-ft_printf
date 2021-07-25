#include "../ft_printf.h"
#include <stdio.h>
#include <stdint.h>

char *ft_rev(char *str)
{
	int len;
	char *ret;
	int i;

	len = ft_strlen(str);
	ret = malloc(len + 1);
	i = 0;
	while (len--)
	{
		ret[i] = str[len];
		i++;
	}
	return (ret);
}

char	*to_hex(long long num)
{
	char ret[1024];
	int i;
	int neg_flag;

	i = 0;
	neg_flag = 0;
	if (num == 0)
		return ("0\0");
	if (num < 0)
	{
		neg_flag = 1;
		num *= -1;
	}
	while (num > 0)
	{
		ret[i] = (num % 16) + 48;
		if (((num % 16) + 48) > 57)
			ret[i] = (num % 16) + 87;
		num = num / 16;
		i++;
	}
	if (neg_flag)
		ret[i++] = '-';
	ret[i] = 0;
	return (ft_rev(ret));
}

void	printf_ptr(obj* flags)
{
	char		*ptr;
	uintptr_t	conv;
	char		*str;
	char		*prefix;

	prefix = "0x";
	ptr = va_arg(flags->args, void *);
	conv = (uintptr_t) ptr;
	str = to_hex(conv);
	ft_putstr_fd(prefix, 1);
	ft_putstr_fd(str, 1);
	free(str);
	flags->count += ft_strlen(str) + 2;
}