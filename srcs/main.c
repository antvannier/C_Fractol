/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:07:13 by avannier          #+#    #+#             */
/*   Updated: 2016/03/14 11:07:15 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(-1);
}

void	choose_fractal(t_env *e)
{
	if (ft_strcmp(e->title, "Sier") == 0)
		triangle_sierpinski(e);
	if (ft_strcmp(e->title, "Man") == 0)
		draw_mandelbrot(e);
	if (ft_strcmp(e->title, "Jul") == 0)
		draw_julia(e);
	if (ft_strcmp(e->title, "Mb") == 0)
		draw_mandelbis(e);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_error(
		"usage : ./fractol Jul/Man/Mb/Sier");
	if ((ft_strcmp(av[1], "Jul") != 0) && (ft_strcmp(av[1], "Man")
	!= 0) && (ft_strcmp(av[1], "Sier") != 0) && (ft_strcmp(av[1], "Mb") != 0))
		ft_error(
		"usage : ./fractol Jul/Man/Mb/Sier");
	e.title = av[1];
	if ((ft_strcmp(av[1], "Jul") == 0) || (ft_strcmp(av[1], "Man")
	== 0) || (ft_strcmp(av[1], "Sier") == 0) || (ft_strcmp(av[1], "Mb") == 0))
	{
		init_env(&e);
		choose_fractal(&e);
		mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
		mlx_hook(e.win, MOTIONNOTIFY, POINTERMOTIONMASK, capture_mouse_pos, &e);
		mlx_key_hook(e.win, &ft_keypress, &e);
		mlx_key_hook(e.menu_win, &menu_close, &e);
		mlx_mouse_hook(e.win, &ft_mousepress, &e);
		mlx_loop_hook(e.mlx, &animation, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}
