/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:05:37 by avannier          #+#    #+#             */
/*   Updated: 2016/03/14 11:05:38 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_keypress(int keycode, t_env *e)
{
	if (keycode == 76)
	{
		clear_map(e);
		get_point(e);
		choose_fractal(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	if (keycode == 69 || keycode == 78)
		increase_deacrease(keycode, e);
	if (keycode == 123 || keycode == 124)
		ft_keypress2(keycode, e);
	if (keycode == 126 || keycode == 125)
		ft_keypress2(keycode, e);
	if (keycode == 53)
	{
		clear_map(e);
		exit(0);
	}
	if (keycode == 12)
		e->loop = 1;
	if (keycode == 0)
		e->loop = 0;
	return (0);
}

int		ft_keypress2(int keycode, t_env *e)
{
	if (keycode == 124)
		move_map(e, (double)WIN_W * 0.05, 0);
	if (keycode == 123)
		move_map(e, (double)WIN_W * -0.05, 0);
	if (keycode == 125)
	{
		if (e->title[0] == 'J' || e->title[0] == 'M')
			move_map(e, 0, (double)WIN_H * 0.05);
		if (e->title[0] == 'S')
			move_map(e, 0, (double)WIN_H * -0.05);
	}
	if (keycode == 126)
	{
		if (e->title[0] == 'J' || e->title[0] == 'M')
			move_map(e, 0, (double)WIN_H * -0.05);
		if (e->title[0] == 'S')
			move_map(e, 0, (double)WIN_H * 0.05);
	}
	clear_map(e);
	choose_fractal(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		capture_mouse_pos(int x, int y, t_env *e)
{
	if (ft_strcmp(e->title, "Jul") == 0)
	{
		clear_map(e);
		e->julia_x = e->point.x_1 + ((double)x * e->point.step_x);
		e->julia_y = e->point.y_1 + ((double)y * e->point.step_y);
		choose_fractal(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	return (0);
}

int		ft_mousepress(int button, int x, int y, t_env *e)
{
	if ((button == 4 || button == 1 || button == 2 || button == 5) &&
			(e->title[0] == 'J' || e->title[0] == 'M'))
	{
		zoom_unzoom_jm(button, e, x, y);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	if ((button == 4 || button == 1 || button == 2 || button == 5) &&
			(e->title[0] == 'S'))
		zoom_unzoom_s(button, e, x, y);
	return (0);
}

int		increase_deacrease(int keycode, t_env *e)
{
	if (keycode == 69)
	{
		clear_map(e);
		if (e->title[0] == 'S')
			e->nb_i == 13 ? e->nb_i = 13 : e->nb_i++;
		if (e->title[0] == 'J' || (e->title[0] == 'M'))
			e->nb_i += 20;
		choose_fractal(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	if (keycode == 78)
	{
		clear_map(e);
		if (e->title[0] == 'S')
			e->nb_i = (e->nb_i == 0 ? 0 : e->nb_i - 1);
		if (e->title[0] == 'J' || (e->title[0] == 'M'))
			e->nb_i = (e->nb_i == 50 ? 50 : e->nb_i - 20);
		choose_fractal(e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	return (0);
}
