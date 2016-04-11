/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:10:22 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:10:23 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	i;

	if (n != 0)
	{
		ptr = (unsigned char*)s;
		i = 0;
		while (i < n)
		{
			if ((unsigned char)c == ptr[i])
				return ((void*)(ptr + i));
			i++;
		}
	}
	return (NULL);
}
