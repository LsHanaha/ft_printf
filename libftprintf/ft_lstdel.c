/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:23:11 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:38:15 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	while (*alst)
	{
		temp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		(*alst)->content = NULL;
		free(*alst);
		*alst = temp;
	}
}
