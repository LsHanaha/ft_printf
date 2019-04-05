/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:48:00 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:38:24 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static void	ft_lstclear_list(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst->content);
		lst->content = NULL;
		free(lst);
		lst = temp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*iter;
	t_list	*first;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(first = (f)(lst)))
		return (NULL);
	iter = first;
	lst = lst->next;
	while (lst)
	{
		if (!(iter->next = (f)(lst)))
		{
			ft_lstclear_list(first);
			return (NULL);
		}
		iter = (iter)->next;
		lst = lst->next;
	}
	return (first);
}
