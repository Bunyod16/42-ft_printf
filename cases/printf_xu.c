#include "../ft_printf.h"
#include <limits.h>

static char	*to_hex2(long long num)
{
	char	ret[1024];
	int		i;

	i = 0;
	while (num > 0)
	{
		ret[i] = (num % 16) + 48;
		if (((num % 16) + 48) > 57)
			ret[i] = (num % 16) + 55;
		num = num / 16;
		i++;
	}
	ret[i] = 0;
	return (ft_rev(ret));
}

void	printf_xu(t_obj *flags)
{
	long long	num;
	char		*hex;

	num = va_arg(flags->args, int);
	if (num == 0)
	{
		ft_printf("%d", 0);
		flags->count += 1;
		return ;
	}
	if (num < 0)
		num = UINT_MAX + num + 1;
	hex = to_hex2(num);
	ft_putstr_fd(hex, 1);
	flags->count = ft_strlen(hex);
	free(hex);
}
