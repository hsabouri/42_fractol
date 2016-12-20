/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 15:05:03 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/20 13:50:45 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	static t_env	env;

	env.width = 1200;
	env.height = 1200;
	env.offsetx = env.width / 2;
	env.offsety = env.height / 2;
	env.coefx = 4 / (double)env.width;
	env.coefy = 4 / (double)env.height;
	env.fractal = JULIA;
	env.jx = 0;
	env.jy = 0;
	env.iter = 50;
	env.inc_iter = 2;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.width, env.height, "Fract'ol");
	env.image = g_new_image(env);
	env.colormod = 75;
	mlx_loop_hook(env.mlx, g_looped, &env);
	mlx_key_hook(env.win, g_keyboard_1, &env);
	mlx_mouse_hook(env.win, g_mouse_click, &env);
	mlx_hook(env.win, MOTIONNOTIFY, POINTERMOTIONMASK, g_mouse, &env);
	mlx_loop(env.mlx);
	return (0);
}
