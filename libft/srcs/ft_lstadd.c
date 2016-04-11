/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:07:34 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:07:36 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd(t_list **alst, t_list *new_lst)
{
	t_list		*element;

	if (alst)
	{
		element = *alst;
		new_lst->next = element;
		*alst = new_lst;
	}
}
