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

static void	process_specifier(t_obj *flags, const char *str, int i)
{
	if (str[i] == 'c')
		process_char(flags);
	if (str[i] == 's')
		process_str(flags);
	if (str[i] == 'p')
		process_ptr(flags);
	if (str[i] == 'd' || str[i] == 'i')
		process_dec(flags);
	if (str[i] == 'u')
		process_u(flags);
	if (str[i] == 'x' || str[i] == 'X')
		process_x(flags);
	if (str[i] == '%')
	{
		ft_putchar_fd('%', 1);
		flags->count += 1;
	}
}

static int	detect_specifier(char c)
{
	static char	*specifiers = "cspdiuxX%";
	int			i;

	i = 0;
	while (specifiers[i])
		if (specifiers[i++] == c)
			return (1);
	return (0);
}

static int	detect_flags(t_obj *flags, const char *s, int i)
{
	while (!detect_specifier(s[i]))
	{
		if (s[i] == '-')
			flags->dash = 1;
		if (s[i] == ' ')
			flags->sp = 1;
		if (ft_isnum(s[i]) && flags->prc == 0 && s[i - 1] != '.')
			flags->wdt = (flags->wdt * 10) + s[i] - 48;
		else if (ft_isnum(s[i]) && flags->pnt)
			flags->prc = (flags->prc * 10) + s[i] - 48;
		if (s[i] == '0' && flags->wdt == 0 && !flags->dash && !flags->prc)
			flags->zero = 1;
		if (s[i] == '+')
			flags->sign = 1;
		if (s[i] == '.')
			flags->pnt = 1;
		if (s[i] == '#')
			flags->hash = 2;
		i++;
	}
	if (s[i] == 'X')
		flags->big_x = 1;
	process_specifier(flags, s, i);
	return (i);
}

static t_obj	*set_to_zero(t_obj *ls)
{
	ls->wdt = 0;
	ls->prc = 0;
	ls->zero = 0;
	ls->pnt = 0;
	ls->dash = 0;
	ls->count = 0;
	ls->sign = 0;
	ls->sp = 0;
	ls->big_x = 0;
	ls->hash = 0;
	return (ls);
}

int	ft_printf(const char *str, ...)
{
	t_obj	*flags;
	int		i;
	int		count;

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
