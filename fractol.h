/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:25:22 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/03 16:36:48 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "key_define.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define ABS(Value) ((Value < 0) ? (-Value) : (Value))
# define POINTERMOTIONMASK (1L<<6)
# define MOTIONNOTIFY 6
# define RED 2
# define GRE 1
# define BLU 0
# define WIKIPEDIA 0
# define PASTEL 1
# define BURNING 2
# define TITLE "Fract'ol"
# define EXIT 0
# define USAGE 1
# define MALLOC 2
# define FEXIST 3
# define MANDEL 0
# define JULIA 1
# define BSHIP 2
# define STICKY 0

typedef struct	s_image
{
	int		bpp;
	int		width;
	int		height;
	int		endian;
	int		sl;
	char	*data;
	void	*mlx_img;
}				t_image;

typedef	struct	s_color
{
	unsigned char	red;
	unsigned char	gre;
	unsigned char	blu;
}				t_color;

typedef struct	s_pix
{
	int		x;
	int		y;
	t_color	color;
}				t_pix;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	t_image image;
	int		fractal;
	int		lock:2;
	double	jx;
	double	jy;
	double	offsetx;
	double	offsety;
	double	coefx;
	double	coefy;
	double	zoom;
	int		iter;
	int		inc_iter;
	int		colormod;
	int		cscheme;
	int		mode;
}				t_env;

typedef struct	s_thread
{
	t_env	*env;
	int		thread;
}				t_thread;

int				burningship(double cx, double cy, int iteration);
int				mandelbrot(double cx, double cy, int iteration);
int				julia(double zx, double zy, double cx, double cy, int iteration);
void			ft_error(int code);
t_color 		color_wheel(int i, t_env env);
t_color			color_gradient(int i, t_env env, t_color *grad, float *position);
t_color 		weird_gradient(int i, t_env env);
int				g_color_to_hex(t_color color);
t_image			g_new_image(t_env env);
t_image			g_pixel_put(t_image image, int x, int y, t_color color);
void			gs_pixel_put(t_image *image, int x, int y, t_color color);
void			g_refresh_win(t_image image, t_env env);
int				g_looped(t_env *env);
int				g_keyboard_1(int keycode, t_env *env);
t_env			g_zoom(t_env env, double coef);
t_env			g_move(t_env env, double x, double y);
int				g_mouse_click(int button, int x, int y, t_env *env);
int				g_mouse(int x, int y, t_env *env);
t_env			g_init_pos(t_env env);

#endif
