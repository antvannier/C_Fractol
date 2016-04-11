/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:36:20 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:36:22 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char	const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*tmp;

	if (!s || !f)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s));
	if (!tmp)
		return (NULL);
	i = 0;
	while (s[i])
	{
		tmp[i] = (*f)(i, s[i]);
		i++;
	}
	return (tmp);
}
