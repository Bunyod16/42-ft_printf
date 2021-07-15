/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:07:54 by bshamsid          #+#    #+#             */
/*   Updated: 2021/05/19 01:28:05 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	x;

	if (!s)
		return (NULL);
	ret = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	ret[ft_strlen(s)] = 0;
	x = 0;
	while (x < ft_strlen(s))
	{
		ret[x] = (*f)(x, s[x]);
		x++;
	}
	return (ret);
}
