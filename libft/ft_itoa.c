/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 02:58:36 by bshamsid          #+#    #+#             */
/*   Updated: 2021/05/19 01:29:57 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(int n)
{
	if (n == 0)
		return (0);
	else
		return (1 + count_len(n / 10));
}

static unsigned int	convert(int n)
{
	unsigned int	ret;

	if (n < 0)
		ret = (unsigned int)(n * -1);
	else
		ret = (unsigned int)n;
	return (ret);
}

static char	last_digit_to_char(unsigned int n)
{
	if (n == 0)
		return ('0');
	else
		return ((char) '0' + n % 10);
}

char	*ft_itoa(int n)
{
	char			*ret;
	int				x;
	unsigned int	copy;
	int				len;

	len = 1 + count_len(n / 10);
	if (n < 0)
		len++;
	ret = malloc(len + 1);
	if (!ret)
		return (ret);
	ret[len] = '\0';
	if (n < 1 && n > -1)
		ret[0] = '0';
	if (n < 0)
		ret[0] = '-';
	copy = convert(n);
	x = len;
	while (copy)
	{
		ret[--x] = last_digit_to_char(copy);
		copy /= 10;
	}
	return (ret);
}
