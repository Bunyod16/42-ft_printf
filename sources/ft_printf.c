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
#include "stdio.h"

int	detect_flags(obj *flags, const char *str, int i)
{
	while(str[i] != 'c' && str[i] != 's' && str[i] != 'p' &&
	str[i] != 'd' && str[i] != 'i' && str[i] != 'u' &&
	str[i] != 'x' && str[i] != 'X' && str[i] != '%')
	{
		if (str[i] == '-')
			flags->dash = 1;
		if (str[i] == ' ')
			flags->sp = 1;
		if (ft_isnum(str[i]))
			flags->wdt = 1;
		if (str[i] == '0')
			flags->zero = 1;
		if (str[i] == '.')
			flags->prc = 1;
		if (str[i] == '+')
			flags->sign = 1;
	}
	if (str[i] == '%')
		printf_percentage(flags);
	// process_specifier(flags, str, i);
	return (i);
}

// void process_specifier(obj *flags, const char *str, int i)
// {
// 	if (str[i] == 'c')
// 		return ;
// }

obj *set_to_zero(obj *ls)
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
	while (str[++i])
	{
		flags = set_to_zero(flags);
		if (str[i] == '%')
			i = detect_flags(flags, str, i + 1);
		else
			count += write(0, &str[i], 1);
		count += flags->count;
	}
	va_end(flags->args);
	free (flags);
	return (count);
}