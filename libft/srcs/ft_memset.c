/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:12:14 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:12:51 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char *i;

	if (n == 0)
		return (s);
	i = (char *)s;
	while (n != '\0')
	{
		n--;
		*i = (char)c;
		i++;
	}
	return (s);
}
