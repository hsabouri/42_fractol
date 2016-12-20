/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mouse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:19:53 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/20 20:27:48 by hsabouri         ###   ########.fr       */
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
	if (x > env->width || y > env->height || x < 0 || y < 0)
		return (0);
	if (button == 1)
	{
		env->offsetx = env->offsetx - (x - env->width / 2) * env->coefx * (env->width / 4);
		env->offsety = env->offsety - (y - env->height / 2) * env->coefy * (env->height / 4);
	}
	printf("Bouton : %d\n", button);
	return (0);
}
