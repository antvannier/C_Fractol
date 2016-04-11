/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:43:12 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:43:13 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *tmp;

	tmp = dest;
	while (*tmp)
		tmp++;
	while (*src && n > 0)
	{
		*tmp = *src;
		tmp++;
		src++;
		n--;
	}
	*tmp = '\0';
	return (dest);
}
