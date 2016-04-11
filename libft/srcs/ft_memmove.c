/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:12:02 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:12:03 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp;
	unsigned char		*tmp2;

	tmp = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	if (dst > src)
	{
		tmp = tmp + n;
		tmp2 = tmp2 + n;
		while (n--)
			*--tmp = *--tmp2;
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
