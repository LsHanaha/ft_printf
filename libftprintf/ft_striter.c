/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshanaha <lshanaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:42:43 by lshanaha          #+#    #+#             */
/*   Updated: 2019/01/14 17:40:06 by lshanaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	n;

	if (s == NULL || f == NULL)
		return ;
	n = 0;
	while (s[n])
	{
		(*f)(&(s[n]));
		n++;
	}
}
