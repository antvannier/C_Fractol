/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:05:48 by avannier          #+#    #+#             */
/*   Updated: 2016/03/14 11:05:49 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		zoom_unzoom_jm(int button, t_env *e, int x, int y)
{
	clear_map(e);
	move_map(e, x - WIN_W / 2, y - WIN_H / 2);
	if ((button == 4 || button == 1) &&
			(e->title[0] == 'J' || e->title[0] == 'M'))
	{
		e->point.x_1 += e->point.step_x * (WIN_W / 4);
		e->point.y_1 += e->point.step_y * (WIN_H / 4);
		e->point.x_2 -= e->point.step_x * (WIN_W / 4);
		e->point.y_2 -= e->point.step_y * (WIN_H / 4);
		e->point.step_x = (e->point.x_2 - e->point.x_1) / WIN_W;
		e->point.step_y = (e->point.y_2 - e->point.y_1) / WIN_H;
	}
	if ((button == 5 || button == 2) &&
			(e->title[0] == 'J' || e->title[0] == 'M'))
	{
		e->point.x_1 -= e->point.step_x * (WIN_W / 4);
		e->point.y_1 -= e->point.step_y * (WIN_H / 4);
		e->point.x_2 += e->point.step_x * (WIN_W / 4);
		e->point.y_2 += e->point.step_y * (WIN_H / 4);
		e->point.step_x = (e->point.x_2 - e->point.x_1) / WIN_W;
		e->point.step_y = (e->point.y_2 - e->point.y_1) / WIN_H;
	}
	move_map(e, (x - WIN_W / 2) * -1, (y - WIN_H / 2) * -1);
	choose_fractal(e);
	return (0);
}

int		zoom_unzoom_s(int button, t_env *e, int x, int y)
{
	clear_map(e);
	move_map(e, x + WIN_W / 2, y + WIN_H / 2);
	e->zoom += 5;
	if ((button == 4 || button == 1) && (e->title[0] == 'S'))
	{
		e->point.x_1 -= e->zoom;
		e->point.y_1 += e->zoom;
		e->point.x_2 += e->zoom;
		e->point.y_2 += e->zoom;
		e->point.step_y -= e->zoom;
	}
	if ((button == 5 || button == 2) && (e->title[0] == 'S'))
	{
		e->point.x_1 += e->zoom;
		e->point.y_1 -= e->zoom;
		e->point.x_2 -= e->zoom;
		e->point.y_2 -= e->zoom;
		e->point.step_y += e->zoom;
	}
	move_map(e, (x + WIN_W / 2) * -1, (y + WIN_H / 2) * -1);
	choose_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		menu_close(int keycode, t_env *e)
{
	e->j = 1;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	animation_s(t_env *e)
{
	if (e->i_way == 1)
	{
		e->nb_i++;
		if (e->nb_i == 12)
			e->i_way = 0;
	}
	if (e->i_way == 0)
	{
		e->nb_i--;
		if (e->nb_i == 5)
			e->i_way = 1;
	}
	clear_map(e);
	choose_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_expose_hook(e->win, &ft_keypress, &e);
	usleep(200000);
}

void	animation_jm(t_env *e)
{
	if (e->i_way == 1)
	{
		e->nb_i += 20;
		if (e->nb_i == 360)
			e->i_way = 0;
	}
	if (e->i_way == 0)
	{
		e->nb_i -= 20;
		if (e->nb_i == 100)
			e->i_way = 1;
	}
	clear_map(e);
	choose_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_expose_hook(e->win, &ft_keypress, &e);
	usleep(200000);
}
