/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_keyboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:15:10 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/02 17:42:47 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		g_keyboard_1(int keycode, t_env *env)
{
	if (keycode == ADD)
		env->iter += 20;
	if (keycode == SUB)
		env->iter -= (env->iter >= 21) ? 20 : env->iter - 1;
	if (keycode == ENTER)
		env->inc_iter = (env->inc_iter == 0) ? 2 : 0;
	if (keycode == C)
		env->cscheme += (env->cscheme == 2) ? -2 : 1;
	if (keycode == F)
		env->fractal += (env->fractal == 3) ? -2 : 1;
	if (keycode == F)
		env->iter = 50;
	if (keycode == L)
		env->lock = (env->lock == 1) ? 0 : 1;
	if (keycode == R)
		*env = g_init_pos(*env);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == N9)
		env->colormod++;
	if (keycode == N6)
		env->colormod -= (env->colormod > 1) ? 1 : 0;
	if (keycode == N3)
		env->mode = (env->mode == STICKY) ? 1 : STICKY;
	return (0);
}
