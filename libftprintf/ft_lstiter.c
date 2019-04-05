/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:43:31 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:38:21 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*iter;

	if (lst == NULL || f == NULL)
		return ;
	iter = lst;
	while (iter)
	{
		(f)(iter);
		iter = iter->next;
	}
}
