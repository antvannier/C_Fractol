/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avannier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 11:12:05 by avannier          #+#    #+#             */
/*   Updated: 2016/03/14 11:12:07 by avannier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <mlx.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# define WIN_W 800
# define WIN_H 600
# define MENU_W 400
# define MENU_H 600
# define RED 0xff0000
# define BLUE 0x0000ff
# define GREEN 0x00ff00
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define BLACK 0x000000
# define PURPLE 0xFF00FF
# define GREY 0x686868
# define CYAN 0x0080ff
# define MIDBLUE 0x0000CC
# define CBLUE 0x00ccff
# define SIER 0xD2BCBA
# define POINTERMOTIONMASK (1L<<6)
# define MOTIONNOTIFY  6

typedef struct	s_point
{
	double		x_1;
	double		y_1;
	double		x_2;
	double		y_2;
	double		step_x;
	double		step_y;
}				t_point;

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_cmplx
{
	double		r;
	double		i;
}				t_cmplx;

typedef struct	s_env
{
	t_point			point;
	t_cmplx			z;
	t_cmplx			c;
	int				loop;
	int				i_way;
	void			*mlx;
	void			*win;
	void			*menu_img;
	void			*menu_win;
	void			*img;
	char			*title;
	char			*img_data;
	unsigned int	color;
	int				s_line;
	int				ed;
	int				nb_i;
	int				j;
	int				i;
	int				x;
	int				y;
	double			tmp;
	double			bpp;
	int				bit_per_pixel;
	double			zoom;
	double			julia_x;
	double			julia_y;
}				t_env;

/*
** main.c
*/

void			ft_error(char *str);
void			choose_fractal(t_env *e);

/*
** julia.c
*/

void			draw_julia(t_env *e);
void			set_cmplx_j(t_env *e);

/*
** mandelbrot.c
*/

void			draw_mandelbrot(t_env *e);
void			set_cmplx_m(t_env *e);

/*
** mandelbis.c
*/

void			draw_mandelbis(t_env *e);
void			set_cmplx_mb(t_env *e);

/*
** sierpinski.c
*/

void			triangle_sierpinski(t_env *e);
void			sub_triangle(t_env *e, t_coord **tmp, int n);
void			draw_sierpinski(t_env *e, t_coord **p);
void			draw_subtriangle(t_env *e, t_coord **tmp, int n);
int				animation(t_env *e);

/*
** tools.c
*/

void			init_env(t_env *e);
void			clear_map(t_env *e);
void			put_pixel_to_image(int x, int y, t_env *e);
void			get_color(t_env *e);
void			get_point(t_env *e);

/*
** tools2.c
*/

void			fill_img(t_env *e, unsigned long color);
void			draw_line(t_env *e, t_coord *a, t_coord *b);
t_coord			*set_point(double x, double y);
void			move_map(t_env *e, int mx, int my);
void			print_menu(t_env *e);

/*
** key.c
*/

int				ft_keypress(int keycode, t_env *e);
int				capture_mouse_pos(int x, int y, t_env *e);
int				ft_mousepress(int button, int x, int y, t_env *e);
int				ft_keypress2(int keycode, t_env *e);
int				increase_deacrease(int keycode, t_env *e);

/*
** key2.c
*/

int				zoom_unzoom_jm(int button, t_env *e, int x, int y);
int				zoom_unzoom_s(int button, t_env *e, int x, int y);
int				menu_close(int keycode, t_env *e);
void			animation_s(t_env *e);
void			animation_jm(t_env *e);

#endif
