/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:10:04 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:10:06 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	while (n != 0)
	{
		if (*s2 == c)
		{
			*s1 = *s2;
			s1++;
			s2++;
			return (s1);
		}
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	return (NULL);
}
