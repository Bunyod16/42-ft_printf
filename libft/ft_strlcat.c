/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyod16 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:05:33 by bunyod16          #+#    #+#             */
/*   Updated: 2021/05/15 11:28:29 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src,
		size_t dstsize)
{
	size_t	count;

	if (dstsize < 1)
		return (ft_strlen(src));
	count = 0;
	while (*dst != '\0' && count < dstsize)
	{
		dst++;
		count++;
	}
	while (*src != '\0' && count < dstsize - 1)
	{
		*dst++ = *src++;
		count++;
	}
	if (count < dstsize)
		*dst = '\0';
	while (*src++ != '\0')
		count++;
	return (count);
}
