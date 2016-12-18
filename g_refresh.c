/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_refresh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:08:39 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/18 18:17:43 by hsabouri         ###   ########.fr       */
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
			color = julia((double)(j - env->offsetx) * env->coefx,
			(double)(i - env->offsety) * env->coefy,
			env->jx, env->jy, env->iter);
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
