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
#include <stdio.h>

static void process_specifier(t_obj *flags, const char *str, int i)
{
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
	if (str[i] == '%')
	{
		ft_putchar_fd('%', 1);
		flags->count += 1;
	}
}

static int	detect_flags(t_obj *flags, const char *str, int i)
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
		{
			if (flags->prc == 0 && str[i - 1] != '.')
				flags->wdt = (flags->wdt*10) + str[i] - 48;
			else
				flags->prc = (flags->prc * 10) + str[i] - 48; 
		}
		if (str[i] == '0' && flags->wdt == 0)
			flags->zero = 1;
		if (str[i] == '+')
			flags->sign = 1;
		if (str[i] == '.')
			flags->pnt = 1;
		i++;
	}
	process_specifier(flags, str, i);
	return (i);
}

static t_obj *set_to_zero(t_obj *ls)
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
	t_obj *flags;
	int i;
	int count;

	count = 0;
	flags = (t_obj *)malloc(sizeof(t_obj));
	if (!flags)
		return (-1);
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