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

#include "ft_printf.h"

obj *set_to_zero(obj *ls)
{
	ls->wdt = 0;
	ls->prc = 0;
	ls->zero = 0;
	ls->pnt = 0;
	ls->dash = 0;
	ls->tl = 0;
	ls->sign = 0;
	ls->is_zero = 0;
	ls->perc = 0;
	ls->sp = 0;
	return (ls);
}

int	ft_printf(const char *str, ...)
{
	obj *flags;

	flags = (obj *)malloc(sizeof(obj));
	if (!flags)
		return (-1);
	if (!ft_strchr(str,'%'))
	{
		str = (char *) str;
		ft_putstr_fd(str, 0);
	}
	flags = set_to_zero(flags);
}