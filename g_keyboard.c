/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_keyboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:15:10 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/20 19:19:47 by hsabouri         ###   ########.fr       */
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
	if (keycode == 8)
		env->cscheme += (env->cscheme == 2) ? -2 : 1;
	if (keycode == 3)
		env->fractal += (env->fractal == 3) ? -2 : 1;
	if (keycode == 3)
		env->iter = 50;
	if (keycode == 37)
		env->lock = (env->lock == 1) ? 0 : 1;
	return (0);
}
