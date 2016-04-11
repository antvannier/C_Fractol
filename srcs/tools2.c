/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:06:14 by avannier          #+#    #+#             */
/*   Updated: 2016/03/14 11:06:15 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fill_img(t_env *e, unsigned long color)
{
	e->y = 0;
	e->color = mlx_get_color_value(e->mlx, color);
	while (e->y < WIN_H)
	{
		e->x = 0;
		while (e->x < e->s_line)
		{
			put_pixel_to_image(e->x, e->y, e);
			e->x++;
		}
		e->y++;
	}
}

void	draw_line(t_env *e, t_coord *a, t_coord *b)
{
	t_coord	*p;
	double	i;
	double	len;
	double	n;

	p = set_point(b->x - a->x, b->y - a->y);
	i = 0;
	len = sqrt(p->x * p->x + p->y * p->y);
	while (i <= len)
	{
		n = i / len;
		put_pixel_to_image((int)(a->x + p->x * n),
				(int)(a->y + p->y * n), e);
		i++;
	}
	free(p);
}

t_coord	*set_point(double x, double y)
{
	t_coord *pt;

	pt = (t_coord *)malloc(sizeof(t_coord));
	pt->x = x;
	pt->y = y;
	return (pt);
}

void	move_map(t_env *e, int mx, int my)
{
	if (e->title[0] == 'J' || e->title[0] == 'M')
	{
		e->point.x_1 += e->point.step_x * mx;
		e->point.x_2 += e->point.step_x * mx;
		e->point.y_1 += e->point.step_y * my;
		e->point.y_2 += e->point.step_y * my;
	}
	if (e->title[0] == 'S')
	{
		e->point.x_1 += -0.50 * mx;
		e->point.x_2 += -0.50 * mx;
		e->point.y_1 += -0.50 * my;
		e->point.y_2 += -0.50 * my;
		e->point.step_x += -0.50 * mx;
		e->point.step_y += -0.50 * my;
	}
}

void	print_menu(t_env *e)
{
	mlx_string_put(e->mlx, e->menu_win, 0, 10, RED,
	"-------------COMMAND MENU---------------");
	mlx_string_put(e->mlx, e->menu_win, 20, 50, WHITE,
	"+ : Increase iteration");
	mlx_string_put(e->mlx, e->menu_win, 20, 80, WHITE,
	"- : Decrese iteration");
	mlx_string_put(e->mlx, e->menu_win, 20, 110, WHITE,
	"Arrow : Move");
	mlx_string_put(e->mlx, e->menu_win, 20, 140, WHITE,
	"MWheel up / Mouse 1 : Zoom In");
	mlx_string_put(e->mlx, e->menu_win, 20, 170, WHITE,
	"MWheel Down / Mouse 2 : Zoom Out");
	mlx_string_put(e->mlx, e->menu_win, 20, 200, WHITE,
	"Q : Start Animation");
	mlx_string_put(e->mlx, e->menu_win, 20, 230, WHITE,
	"A : Stop Animation");
	mlx_string_put(e->mlx, e->menu_win, 20, 260, WHITE,
	"Enter : Reset position");
	mlx_string_put(e->mlx, e->menu_win, 20, 290, WHITE,
	"Escape : Exit");
}
