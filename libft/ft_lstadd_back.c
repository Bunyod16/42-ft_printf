/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 17:26:45 by bshamsid          #+#    #+#             */
/*   Updated: 2021/05/20 15:53:24 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ls;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ls = *lst;
	while (ls)
	{
		if (!(ls->next))
		{
			ls->next = new;
			return ;
		}
		ls = ls->next;
	}
}
