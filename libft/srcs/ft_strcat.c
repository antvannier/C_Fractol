/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:38:37 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:38:38 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char *tmp1;
	char *tmp2;

	tmp1 = dest;
	tmp2 = (char *)src;
	while (*tmp1)
		tmp1++;
	while (*tmp2)
	{
		*tmp1 = *tmp2;
		tmp1++;
		tmp2++;
	}
	*tmp1 = '\0';
	return (dest);
}
