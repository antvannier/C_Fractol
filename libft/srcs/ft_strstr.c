/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:45:20 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:45:20 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *tmp;
	const char *tmp2;

	if (*needle == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		tmp = haystack;
		tmp2 = needle;
		while (*tmp == *tmp2 && *tmp && *tmp2)
		{
			tmp++;
			tmp2++;
		}
		if (*tmp2 == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
