/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyod16 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:15:35 by bunyod16          #+#    #+#             */
/*   Updated: 2021/05/12 13:02:40 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	rep;

	rep = (char)c;
	while (*s != '\0')
	{
		if (*s == rep)
			return ((char *)s);
		s++;
	}
	if (*s == rep)
		return ((char *)s);
	return (NULL);
}
