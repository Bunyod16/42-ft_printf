/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:56:46 by bshamsid          #+#    #+#             */
/*   Updated: 2021/05/17 03:13:36 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char *)dst = *(unsigned char *)src;
		if ((unsigned char)c == *(unsigned char *)src)
		{
			*(unsigned char *)dst = *(unsigned char *)src;
			return ((unsigned char *)dst + 1);
		}
		dst++;
		src++;
	}
	return (NULL);
}
