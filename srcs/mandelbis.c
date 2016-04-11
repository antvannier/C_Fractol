/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:06:38 by avannier          #+#    #+#             */
/*   Updated: 2016/03/14 11:06:39 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mandelbis(t_env *e)
{
	const double	save_x = e->point.x_1;
	const double	save_y = e->point.y_1;

	e->y = 0;
	while (e->y < WIN_H)
	{
		e->point.x_1 = save_x;
		e->x = 0;
		while (e->x < WIN_W)
		{
			if (*(unsigned int*)(e->img_data + ((e->bit_per_pixel *
								(e->x)) + e->s_line * (e->y))) == 0x000000)
				set_cmplx_mb(e);
			++e->x;
			e->point.x_1 += e->point.step_x;
		}
		++e->y;
		e->point.y_1 += e->point.step_y;
	}
	e->point.x_1 = save_x;
	e->point.y_1 = save_y;
}

void	set_cmplx_mb(t_env *e)
{
	e->z.r = 0;
	e->z.i = 0;
	e->c.r = e->point.x_1;
	e->c.i = e->point.y_1;
	e->j = 0;
	while (e->j < e->nb_i && (e->z.i * e->z.i + e->z.r * e->z.r)
			< 4)
	{
		e->tmp = e->z.r;
		e->z.r = e->z.r * e->z.r - e->z.i * e->z.i + e->c.r;
		e->z.i = -2 * e->tmp * e->z.i + e->c.i;
		++e->j;
	}
	get_color(e);
	put_pixel_to_image(e->x, e->y, e);
}
