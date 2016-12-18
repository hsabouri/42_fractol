/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:25:22 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/18 18:18:37 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft.h"
# include "key_define.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define ABS(Value) ((Value < 0) ? (-Value) : (Value))
# define POINTERMOTIONMASK (1L<<6)
# define MOTIONNOTIFY 6
# define RED 2
# define GRE 1
# define BLU 0
# define TITLE "Fract'ol"
# define EXIT 0
# define USAGE 1
# define MALLOC 2
# define FEXIST 3
# define MANDEL 1
# define JULIA 2
# define BSHIP 3

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
	double	jx;
	double	jy;
	double	offsetx;
	double	offsety;
	double	coefx;
	double	coefy;
	int		iter;
	int		inc_iter;
	int		speed;
}				t_env;

int				burningship(double cx, double cy, int iteration);
int				mandelbrot(double cx, double cy, int iteration);
int				julia(double zx, double zy, double cx, double cy, int iteration);
void			ft_error(int code);
t_color 		color_wheel(int i, t_env env);
t_color 		color_gradient(int i, t_env env);
t_color 		weird_gradient(int i, t_env env);
int				g_color_to_hex(t_color color);
t_image			g_new_image(t_env env);
t_image			g_pixel_put(t_image image, int x, int y, t_color color);
void			g_refresh_win(t_image image, t_env env);
int				g_looped(t_env *env);
int				g_keyboard_1(int keycode, t_env *env);
void			g_move(int keycode, t_env *env);
int				g_mouse(int x, int y, t_env *env);

#endif
