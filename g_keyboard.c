/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_keyboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:15:10 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/18 18:32:20 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		g_keyboard_1(int keycode, t_env *env)
{
	//if (keycode == DN || keycode == UP || keycode == LT || keycode == RT)
	//	g_move(keycode, env);
	if (keycode == ADD)
		env->iter += 20;
	if (keycode == SUB)
		env->iter -= (env->iter >= 21) ? 20 : env->iter - 1;
	if (keycode == ENTER)
		env->inc_iter = (env->inc_iter == 0) ? 2 : 0;
	return (0);
}
