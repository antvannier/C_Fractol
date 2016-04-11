/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:41:12 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:41:13 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		len;

	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str)
	{
		i = 0;
		while (i < len)
		{
			str[i] = s[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
