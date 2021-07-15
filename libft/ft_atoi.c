/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:18:35 by bshamsid          #+#    #+#             */
/*   Updated: 2021/05/12 13:14:41 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(const char *str)
{
	return ((*str >= 8 && *str <= 13) || *str == 32 );
}

static long long	char_to_int(const char *str)
{
	long long	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res = res + (*str - 48);
		str++;
		if (res > 2147483648)
			return (res);
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (ft_isspace(str) != 0)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	result = sign * char_to_int(str);
	if (result < -2147483648)
		return (0);
	if (result > 2147483647)
		return (-1);
	return ((int)result);
}
