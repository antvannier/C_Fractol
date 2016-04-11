/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:42:02 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:42:03 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 != '\0' && s2 != '\0')
	{
		str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (str)
		{
			str = ft_strcat(str, s1);
			str = ft_strcat(str, s2);
			return (str);
		}
		else if (s1)
			return (ft_strdup(s1));
		else if (s2)
			return (ft_strdup(s2));
	}
	return (NULL);
}
