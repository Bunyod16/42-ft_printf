/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:29:54 by bshamsid          #+#    #+#             */
/*   Updated: 2021/05/17 03:07:24 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	length;

	count = 0;
	length = len;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (len-- > 0 && *haystack)
	{
		if (*haystack == *needle)
			if (ft_strncmp(needle, haystack, ft_strlen(needle)) == 0)
				if (count + ft_strlen(needle) <= length)
					return ((char *)haystack);
		count++;
		haystack++;
	}
	return (NULL);
}
