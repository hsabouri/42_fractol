/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:05:03 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/04 18:57:26 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_help(void)
{
	ft_putendl("\
usage: fractol [set] | help | -h\n\
\n\
Mandelbrot set:\n\
	- \"mandel\"\n\
	- \"mandelbrot\"\n\
Julia set:\n\
	- \"julia\"\n\
Burning-ship set:\n\
	- \"burning\"\n\
	- \"burning-ship\"");
	exit(EXIT_FAILURE);
}

static t_env	env_init(void)
{
	t_env env;

	env.width = (WIDTH > 2560) ? 2560 : WIDTH;
	env.height = (HEIGHT > 1440) ? 1440 : HEIGHT;
	env = g_init_pos(env);
	env.jx = 0;
	env.jy = 0;
	env.iter = 50;
	env.inc_iter = 2;
	env.fractal = MANDEL;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.width, env.height, "Fract'ol");
	env.image = g_new_image(env);
	env.colormod = 75;
	env.mode = STICKY;
	env.cscheme = PASTEL;
	env.lock = 0;
	env.smooth = 0;
	return (env);
}

static t_env	param_parser(t_env env, int ac, char **av)
{
	if (ac == 1)
		env.fractal = MANDEL;
	if (ac == 2)
	{
		if (!ft_strcmp(av[1], "help") || !ft_strcmp(av[1], "-h"))
			ft_help();
		else if (!ft_strcmp(av[1], "julia"))
			env.fractal = JULIA;
		else if (!ft_strcmp(av[1], "mandelbrot") || !ft_strcmp(av[1], "mandel"))
			env.fractal = MANDEL;
		else if (!ft_strcmp(av[1], "burning") ||
		!ft_strcmp(av[1], "burning-ship"))
			env.fractal = BSHIP;
		else
			ft_help();
	}
	if (ac > 2)
		ft_help();
	return (env);
}

int				main(int ac, char **av)
{
	t_env	env;

	env = env_init();
	env = param_parser(env, ac, av);
	mlx_loop_hook(env.mlx, g_looped, &env);
	mlx_key_hook(env.win, g_keyboard_1, &env);
	mlx_mouse_hook(env.win, g_mouse_click, &env);
	mlx_hook(env.win, MOTIONNOTIFY, POINTERMOTIONMASK, g_mouse, &env);
	mlx_loop(env.mlx);
	return (0);
}
