/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_refresh.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 10:08:39 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/02 19:13:23 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

	if (env->mode == STICKY)
		env->colormod = env->iter;
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
	g_refresh_win(env->image, *env);
	return (0);
}

/*
void		*g_threaded(void *thread_ptr)
{
	t_thread		*thread;
	int 			color;
	int				i;
	int				j;

	thread = (t_thread *)thread_ptr;
	i = thread->thread;
	while (i < thread->env->height)
	{
		j = 0;
		while (j < thread->env->width)
		{
			color = g_fract_chooser(i, j, *(thread->env));
			gs_pixel_put(&(thread->env->image), j, i,
				color_wheel(color, *(thread->env)));
			j++;
		}
		i += 8;
	}
	pthread_exit(NULL);
}

int			g_looped(t_env *env)
{
	pthread_t		thread_id[8];
	t_thread		thr_tab[8];
	int				thread;

	if (env->mode == STICKY)
		env->colormod = env->iter;
	thread = 0;
	while (thread < 8)
	{
		thr_tab[thread].env = env;
		thr_tab[thread].thread = thread;
		pthread_create(&(thread_id[thread]), NULL, g_threaded, thr_tab + thread);
		thread++;
	}
	env->iter += env->inc_iter;
	g_refresh_win(env->image, *env);
	return (0);
}
 * */
