/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:14:46 by avannier          #+#    #+#             */
/*   Updated: 2016/03/02 10:14:47 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int x, unsigned int y)
{
	int tmp;

	if (y == 0)
		return (1);
	tmp = ft_power(x, y / 2);
	if (y % 2 == 0)
		return (tmp * tmp);
	else
		return (x * tmp * tmp);
}
