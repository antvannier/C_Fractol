/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:42:24 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:42:24 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;

	i = ft_strlen(dest);
	if (n <= i)
		return (n + ft_strlen(src));
	dest = ft_strncat(dest, src, n - ft_strlen(dest) - 1);
	return (i + ft_strlen(src));
}
