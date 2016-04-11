/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:06:03 by avannier          #+#    #+#             */
/*   Updated: 2016/03/14 11:42:54 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_env(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		ft_error("mlx_init() error");
	if (!(e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, e->title)))
		ft_error("mlx_new_window() error");
	if (!(e->menu_win = mlx_new_window(e->mlx, MENU_W, MENU_H,
					"LE MENU C EST GENIAL")))
		ft_error("mlx_new_window() error");
	if (!(e->img = mlx_new_image(e->mlx, WIN_W, WIN_H)))
		ft_error("mlx_new_image() error");
	if (!(e->menu_img = mlx_new_image(e->mlx, MENU_W, MENU_H)))
		ft_error("mlx_new_image() error");
	e->img_data = mlx_get_data_addr(e->img, &e->bit_per_pixel, &e->s_line,
			&e->ed);
	e->zoom = 1;
	e->loop = 0;
	e->i_way = 1;
	e->nb_i = 100;
	if (e->title[0] == 'S')
		e->nb_i = 6;
	e->bpp = e->bit_per_pixel / 8;
	print_menu(e);
	get_point(e);
}

void	clear_map(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img_data);
	mlx_clear_window(e->mlx, e->win);
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->img_data = mlx_get_data_addr(e->img, &(e->bit_per_pixel), &(e->s_line),
			&(e->ed));
}

void	get_color(t_env *e)
{
	unsigned int	c;

	if (ft_strcmp(e->title, "Jul") == 0)
	{
		c = (e->j * (e->j + e->j) % 256);
		c = (128 << 24 | c << 16 | c << 8 | c << 2);
	}
	if (ft_strcmp(e->title, "Man") == 0 ||
			ft_strcmp(e->title, "Mb") == 0)
	{
		c = mlx_get_color_value(e->mlx, MIDBLUE);
		if (e->j < 7)
			c = 110 << 24 | c << 2;
		if (e->j >= 7 && e->j <= 15)
			c = 110 << 24 | c << 2;
		if (e->j == e->nb_i && (c = mlx_get_color_value(e->mlx, GREEN)))
			c = 60 << 24 | c << 8 | c << 2;
		if (e->j > 20 && e->j != e->nb_i && (c = cos(e->j % 255) * 256))
			c = 10 << 24 | c << 16 | c << 2;
	}
	if (ft_strcmp(e->title, "Sier") == 0 && (c = (rand() % 255) * 256))
		c = 0 << 24 | c << 8 | c << 2;
	e->color = mlx_get_color_value(e->mlx, c);
}

void	put_pixel_to_image(int x, int y, t_env *e)
{
	if (x <= WIN_W && y <= WIN_H && x > 0 && y > 0)
		*(unsigned int*)(e->img_data + ((int)(e->bpp *
						(x)) + e->s_line * (y))) = e->color;
}

void	get_point(t_env *e)
{
	if (ft_strcmp(e->title, "Jul") == 0)
		e->point = (t_point){1.5, -1, -1.5, 1, (-3 / e->zoom) / WIN_W,
			(2 / e->zoom) / WIN_H};
	if (ft_strcmp(e->title, "Man") == 0)
		e->point = (t_point){-2, 1, 1, -1, (3 / e->zoom) / WIN_W,
			(-2 / e->zoom) / WIN_H};
	if (ft_strcmp(e->title, "Sier") == 0)
		e->point = (t_point){10, WIN_H - 10, WIN_W - 10, WIN_H - 10, WIN_W / 2,
			10};
	if (ft_strcmp(e->title, "Mb") == 0)
		e->point = (t_point){-2, 1, 1, -1, (3 / e->zoom) / WIN_W,
			(-2 / e->zoom) / WIN_H};
}
