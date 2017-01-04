/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mouse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:19:53 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/04 13:54:12 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		g_mouse(int x, int y, t_env *env)
{
	if (env->fractal == JULIA && env->lock == 0)
	{
		if (x > env->width || y > env->height || x < 0 || y < 0)
			return (0);
		env->inc_iter = 2;
		env->iter = 50;
		env->jx = (x - (env->width / 2)) * 4 / (double)env->width;
		env->jy = (y - (env->height / 2)) * 4 / (double)env->height;
	}
	return (0);
}

int		g_mouse_click(int button, int x, int y, t_env *env)
{
	double	rx;
	double	ry;

	rx = (x - env->width / 2);
	ry = (y - env->height / 2);
	if (x > env->width || y > env->height || x < 0 || y < 0)
		return (0);
	if (button == 1 || button == 4)
	{
		*env = g_zoom(*env, 0.93);
		env->zoom *= 1 / 0.93;
		env->offsetx -= (0.07 * rx) * env->zoom;
		env->offsety -= (0.07 * ry) * env->zoom;
	}
	if (button == 2 || button == 5)
	{
		*env = g_zoom(*env, 1.07);
		env->zoom /= 1 / 0.93;
		env->offsetx += (0.07 * rx) * env->zoom;
		env->offsety += (0.07 * ry) * env->zoom;
	}
	return (0);
}
