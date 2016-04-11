/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:05:51 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:06:01 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		char_counter(int n)
{
	int i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 1;
	len = char_counter(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[len] = '\0';
	if (n < 0)
	{
		sign = -1;
		str[0] = '-';
	}
	len = len - 1;
	while (n)
	{
		str[len] = (((n % 10) * sign) + '0');
		len--;
		n = n / 10;
	}
	return (str);
}
