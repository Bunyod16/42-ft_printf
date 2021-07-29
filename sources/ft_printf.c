/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 01:26:19 by marvin            #+#    #+#             */
/*   Updated: 2021/07/13 01:26:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void process_specifier(obj *flags, const char *str, int i)
{
	if (str[i] == '%')
		printf_percentage(flags);
	if (str[i] == 'c')
		process_char(flags);
	if (str[i] == 's')
		process_str(flags);
	if (str[i] == 'p')
		process_ptr(flags);
	if (str[i] == 'd')
		process_dec(flags);
	if (str[i] == 'i')
		process_int(flags);
	if (str[i] == 'u')
		process_u(flags);
	if (str[i] == 'x' || str[i] == 'X')
		process_x(flags, str[i]);
}

static int	detect_flags(obj *flags, const char *str, int i)
{
	while(str[i] != 'c' && str[i] != 's' && str[i] != 'p' &&
	str[i] != 'd' && str[i] != 'i' && str[i] != 'u' &&
	str[i] != 'x' && str[i] != 'X' && str[i] != '%')
	{
		if (str[i] == '-')
			flags->dash = 1;
		if (str[i] == ' ')
			flags->sp = 1;
		if (ft_isnum(str[i]) && flags->prc == 0)
			flags->wdt = (flags->wdt*10) + str[i] - 48;
		if (str[i] == '0')
			flags->zero = 1;
		if (str[i] == '+')
			flags->sign = 1;
		if (str[i] == '.')
			flags->prc = 1;
		i++;
	}
	process_specifier(flags, str, i);
	return (i);
}

static obj *set_to_zero(obj *ls)
{
	ls->wdt = 0;
	ls->prc = 0;
	ls->zero = 0;
	ls->pnt = 0;
	ls->dash = 0;
	ls->count = 0;
	ls->sign = 0;
	ls->is_zero = 0;
	ls->sp = 0;
	return (ls);
}

int	ft_printf(const char *str, ...)
{
	obj *flags;
	int i;
	int count;

	flags = (obj *)malloc(sizeof(obj));
	if (!flags)
		return (-1);
	count = 0;
	i = -1;
	va_start(flags->args, str);
	while (str[++i])
	{
		flags = set_to_zero(flags);
		if (str[i] == '%')
			i = detect_flags(flags, str, i + 1);
		else
		{
			count += write(1, &str[i], 1);
		}
		count += flags->count;
	}
	va_end(flags->args);
	free (flags);
	return (count);
}