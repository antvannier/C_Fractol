/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:06:54 by avannier          #+#    #+#             */
/*   Updated: 2016/03/14 11:06:56 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_subtriangle(t_env *e, t_coord **tmp, int n)
{
	t_coord *v[3];

	v[0] = set_point((tmp[0]->x + tmp[1]->x) / 2.0 + (tmp[1]->x - tmp[2]->x)
		/ 2.0, (tmp[0]->y + tmp[1]->y) / 2.0 + (tmp[1]->y - tmp[2]->y) / 2.0);
	v[1] = set_point((tmp[0]->x + tmp[1]->x) / 2.0 + (tmp[0]->x - tmp[2]->x)
		/ 2.0, (tmp[0]->y + tmp[1]->y) / 2.0 + (tmp[0]->y - tmp[2]->y) / 2.0);
	v[2] = set_point((tmp[0]->x + tmp[1]->x) / 2.0, (tmp[0]->y + tmp[1]->y)
		/ 2.0);
	sub_triangle(e, v, n);
	v[0] = set_point((tmp[2]->x + tmp[1]->x) / 2.0 + (tmp[1]->x - tmp[0]->x)
		/ 2.0, (tmp[2]->y + tmp[1]->y) / 2.0 + (tmp[1]->y - tmp[0]->y) / 2.0);
	v[1] = set_point((tmp[2]->x + tmp[1]->x) / 2.0 + (tmp[2]->x - tmp[0]->x)
		/ 2.0, (tmp[2]->y + tmp[1]->y) / 2.0 + (tmp[2]->y - tmp[0]->y) / 2.0);
	v[2] = set_point((tmp[2]->x + tmp[1]->x) / 2.0, (tmp[2]->y + tmp[1]->y)
		/ 2.0);
	sub_triangle(e, v, n);
	v[0] = set_point((tmp[0]->x + tmp[2]->x) / 2.0 + (tmp[2]->x - tmp[1]->x)
		/ 2.0, (tmp[0]->y + tmp[2]->y) / 2.0 + (tmp[2]->y - tmp[1]->y) / 2.0);
	v[1] = set_point((tmp[0]->x + tmp[2]->x) / 2.0 + (tmp[0]->x - tmp[1]->x)
		/ 2.0, (tmp[0]->y + tmp[2]->y) / 2.0 + (tmp[0]->y - tmp[1]->y) / 2.0);
	v[2] = set_point((tmp[0]->x + tmp[2]->x) / 2.0, (tmp[0]->y + tmp[2]->y)
		/ 2.0);
	sub_triangle(e, v, n);
}

void	sub_triangle(t_env *e, t_coord **tmp, int n)
{
	e->j = n;
	get_color(e);
	draw_line(e, tmp[0], tmp[1]);
	draw_line(e, tmp[0], tmp[2]);
	draw_line(e, tmp[1], tmp[2]);
	if (e->j < e->nb_i)
	{
		draw_subtriangle(e, tmp, e->j + 1);
	}
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
}

void	draw_sierpinski(t_env *e, t_coord **p)
{
	t_coord *tmp[3];

	e->j = 1;
	draw_line(e, p[0], p[1]);
	draw_line(e, p[0], p[2]);
	draw_line(e, p[1], p[2]);
	tmp[0] = set_point((p[0]->x + p[1]->x) / 2.0, (p[0]->y + p[1]->y) / 2.0);
	tmp[1] = set_point((p[0]->x + p[2]->x) / 2.0, (p[0]->y + p[2]->y) / 2.0);
	tmp[2] = set_point((p[1]->x + p[2]->x) / 2.0, (p[1]->y + p[2]->y) / 2.0);
	sub_triangle(e, tmp, e->j);
	free(p[0]);
	free(p[1]);
	free(p[2]);
}

void	triangle_sierpinski(t_env *e)
{
	t_coord *p[3];

	if (e->zoom < 1)
		e->zoom = e->zoom + 1.0;
	if (e->zoom >= 2)
		e->zoom = e->zoom - 1.0;
	p[0] = set_point(e->point.x_1, e->point.y_1);
	p[1] = set_point(e->point.x_2, e->point.y_2);
	p[2] = set_point(e->point.step_x, e->point.step_y);
	draw_sierpinski(e, p);
}

int		animation(t_env *e)
{
	if (e->loop == 1 && e->title[0] == 'S')
		animation_s(e);
	if (e->loop == 1 && (e->title[0] == 'M' || e->title[0] == 'J'))
		animation_jm(e);
	return (0);
}
