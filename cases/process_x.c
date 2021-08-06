#include "../ft_printf.h"
#include <limits.h>
#include <stdio.h>

static void	count_space_prc(t_obj *flags, char *num)
{
	int	abs_len;
	int	len;

	len = (int) ft_strlen(num);
	abs_len =  (int) ft_strlen(num);
	if (num[0] == '-')
		abs_len -= 1;
	if (abs_len >= flags->prc)
		flags->prc = 0;
	if (flags->prc > abs_len)
		flags->prc = flags->prc - abs_len;
	if (flags->wdt <= 0 || (flags->dash && flags->wdt <= abs_len))
		flags->wdt = 0;
	if (flags->wdt)
		flags->wdt = flags->wdt - len - flags->prc;
	if (flags->wdt <= 0)
		flags->wdt = 0;
	if (flags->prc <= 0)
		flags->prc = 0;
}

static void	printf_x(t_obj *flags, char *s_num)
{
	char	*hash;

	hash = "0x";
	if (flags->big_x)
		hash = "0X";
	if (flags->zero)
	{
		ft_putnchar_fd('0', flags->wdt, 1);
		ft_putstr_fd(s_num, 1);
		return ;
	}
	if (flags->dash)
	{
		if (flags->hash)
			ft_putstr_fd(hash, 1);
		ft_putnchar_fd('0', flags->prc, 1);
		ft_putstr_fd(s_num, 1);
		ft_putnchar_fd(' ', flags->wdt, 1);
	}
	else if (!flags->dash)
	{
		ft_putnchar_fd(' ', flags->wdt, 1);
		if (flags->hash)
			ft_putstr_fd(hash, 1);
		ft_putnchar_fd('0', flags->prc, 1);	
		ft_putstr_fd(s_num, 1);
	}	
}

static char	*to_hex2(long long num, t_obj *flags)
{
	char	ret[1024];
	int		i;
	int		offset;

	if (num == 0)
		return (ft_rev("0"));
	if (!flags->big_x)
		offset = 87;
	else
		offset = 55; 
	i = 0;
	while (num > 0)
	{
		ret[i] = (num % 16) + 48;
		if (((num % 16) + 48) > 57)
			ret[i] = (num % 16) + offset;
		num = num / 16;
		i++;
	}
	ret[i] = 0;
	return (ft_rev(ret));
}

void	process_x(t_obj *flags)
{
	long long	num;
	char		*hex;


	num = va_arg(flags->args, int);
	if (num < 0)
		num = UINT_MAX + num + 1;
	hex = to_hex2(num, flags);
	count_space_prc(flags, hex);
	if (hex[0] == '0' && flags->hash && ft_strlen(hex) == 1)
	{
		ft_putchar_fd('0', 1);
		flags->count += 1;
	}
	else
	{
		printf_x(flags, hex);
		flags->count += ft_strlen(hex) + flags->wdt + flags->prc +
		+ flags->sign + flags->sp + flags->hash;
	}
	free(hex);
}
