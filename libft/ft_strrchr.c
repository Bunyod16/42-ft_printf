/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bunyod16 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:15:35 by bunyod16          #+#    #+#             */
/*   Updated: 2021/05/12 13:11:52 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	rep;

	rep = (char)c;
	last = NULL;
	while (*s != '\0')
	{
		if (*s == rep)
			last = (char *)s;
		s++;
	}
	if (*s == rep)
		last = (char *)s;
	return (last);
}
