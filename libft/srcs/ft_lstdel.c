/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:07:53 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:07:55 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*element;
	t_list	*next;
	t_list	**ptr;

	if (alst)
	{
		element = *alst;
		while (element)
		{
			next = element->next;
			ptr = &element;
			ft_lstdelone(ptr, del);
			element = next;
		}
		*alst = NULL;
	}
}
