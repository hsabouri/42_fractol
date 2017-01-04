/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_refresh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:08:39 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/04 15:39:47 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	g_fract_chooser(int i, int j, t_env env)
{
	if (env.fractal == JULIA)
		return (julia((double)(j - env.offsetx) * env.coefx,\
			(double)(i - env.offsety) * env.coefy,\
			env));
	else if (env.fractal == BSHIP)
		return (burningship((double)(j - env.offsetx) * env.coefx,\
			(double)(i - env.offsety) * env.coefy, env.iter));
	else
		return (mandelbrot((double)(j - env.offsetx) * env.coefx,\
			(double)(i - env.offsety) * env.coefy, env.iter));
}

int			g_looped(t_env *env)
{
	int color;
	int i;
	int j;

	if (env->iter >= 1500)
		env->iter = 1499;
	if (env->mode == STICKY)
		env->colormod = env->iter;
	i = 0;
	while (i < env->height)
	{
		j = 0;
		while (j < env->width)
		{
			color = g_fract_chooser(i, j, *env);
			env->image = g_pixel_put(env->image, j, i,
				color_wheel(color, *env));
			j++;
		}
		i++;
	}
	if (env->smooth)
		env->image = g_epilepsie(env->image);
	env->iter += env->inc_iter;
	g_refresh_win(env->image, *env);
	return (0);
}
