/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:44:27 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:44:28 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	len = ft_strlen(needle);
	while (haystack[i] && i + len - 1 < n)
	{
		if (haystack[i] == *needle)
		{
			j = 0;
			while (haystack[i + j] == needle[j] && (i + j) < n)
			{
				if (needle[1 + j] == '\0' || (i + j) == n - 1)
					return ((char *)haystack + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
