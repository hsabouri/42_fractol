/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mouse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:19:53 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/02 18:03:59 by hsabouri         ###   ########.fr       */
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

	rx = (x - env->width + env->offsetx) * env->coefx;
	ry = (y - env->height + env->offsety) * env->coefy;	
	if (x > env->width || y > env->height || x < 0 || y < 0)
		return (0);
	if (button == 1)
	{
		*env = g_zoom(*env, 0.93);
		env->zoom *= 0.93;
		env->offsetx -= ((1 / 0.93 - 1) * rx) /
			env->coefx;
		env->offsety -= ((1 / 0.93 - 1) * ry) /
			 env->coefy;
	}
	if (button == 2)
	{
		*env = g_zoom(*env, 1.07);
		env->offsetx -= (x - env->width / 2) * (1 / 1.07);
		env->offsety -= (y - env->height / 2) * (1 / 1.07);
	}
	return (0);
}
