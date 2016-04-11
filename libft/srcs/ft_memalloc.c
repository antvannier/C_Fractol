/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:09:50 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:09:53 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *str;

	if (!size)
		return (NULL);
	str = (void *)malloc(size);
	if (!str)
		return (NULL);
	ft_bzero((void *)str, size);
	return ((void *)str);
}
