/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshamsid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 00:57:04 by bshamsid          #+#    #+#             */
/*   Updated: 2021/05/20 15:54:07 by bshamsid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*res;
	int		start;

	start = 1;
	res = NULL;
	while (lst)
	{
		temp = ft_lstnew(lst->content);
		temp->content = f(temp->content);
		if (temp == NULL)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		if (!start)
			ft_lstadd_back(&res, temp);
		else
			res = temp;
		start = 0;
		lst = lst->next;
	}
	return (res);
}
