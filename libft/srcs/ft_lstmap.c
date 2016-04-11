/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:08:52 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:08:53 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*first;

	if (lst && f)
	{
		new = f(lst);
		if (new)
		{
			first = new;
			while (lst->next)
			{
				lst = lst->next;
				new->next = f(lst);
				new = new->next;
				if (!new)
					return (NULL);
			}
			return (first);
		}
	}
	return (NULL);
}
