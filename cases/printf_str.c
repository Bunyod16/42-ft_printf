#include "../ft_printf.h"

void	printf_str(obj* flags)
{
	char *str;
	int i;

	str = va_arg(flags->args, char *);
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	flags->count += i;
}