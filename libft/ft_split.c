/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:49:37 by bshamsid          #+#    #+#             */
/*   Updated: 2021/05/17 04:05:12 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			while (*s && *s == c)
				s++;
	}
	return (i);
}

static int	find_char_index(const char *s, char c)
{
	int	x;

	x = 0;
	while (s[x] != '\0' && s[x] != c)
		x++;
	return (x);
}

char	**ft_split(const char *s, char c)
{
	char	**list;
	int		x;
	int		a;

	if (!s)
		return (NULL);
	list = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (!list)
		return (NULL);
	a = 0;
	while (*s)
	{
		x = 0;
		if (*s != c)
		{
			x = find_char_index(s, c);
			list[a++] = ft_substr(s, 0, x);
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	list[a] = 0;
	return (list);
}
