/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_refresh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:08:39 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/20 15:31:21 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		g_move(int keycode, t_env *env)
{
	if (keycode == UP)
		env->offsety += 0.1;
	if (keycode == DN)
		env->offsety -= 0.1;
}

static int	g_fract_chooser(int i, int j, t_env env)
{
	if (env.fractal == JULIA)
		return (julia((double)(j - env.offsetx) * env.coefx,\
			(double)(i - env.offsety) * env.coefy,\
			env.jx, env.jy, env.iter));
	else if (env.fractal == BSHIP)
		return (burningship((double)(j - env.offsetx) * env.coefx,\
			(double)(i - env.offsety) * env.coefy, env.iter));
	else
		return (mandelbrot((double)(j - env.offsetx) * env.coefx,\
			(double)(i - env.offsety) * env.coefy, env.iter));
}

int			g_looped(t_env *env)
{
	int 			color;
	int				i;
	int				j;

	i = 0;
	while (i < env->height)
	{
		j = 0;
		while (j < env->width)
		{
			color = g_fract_chooser(i, j, *env);
			env->image = g_pixel_put(env->image, j, i, color_wheel(color, *env));
			j++;
		}
		i++;
	}
	env->iter += env->inc_iter;
	/*
	env->coefx = (4 * coef) / (double)env->width;
	env->coefy = (4 * coef) / (double)env->height;
	env->offsetx = 1.202829 / env->coefx;
	env->offsety = 0.19819 / env->coefy;
	*/
	g_refresh_win(env->image, *env);
	return (0);
}
