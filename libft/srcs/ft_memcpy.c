/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:11:31 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:11:32 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;

	if (n == 0 || dst == src)
		return (dst);
	s1 = (char *)dst;
	s2 = (const char *)src;
	while (n != 0)
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	return (dst);
}
