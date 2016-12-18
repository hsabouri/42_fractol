/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mouse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 13:19:53 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/17 18:14:31 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		g_mouse(int x, int y, t_env *env)
{
	if (env->fractal == JULIA)
	env->inc_iter = 2;
	env->iter = 50;
	env->jx = (x - (env->width / 2)) / (double)env->width;
	env->jy = (y - (env->height / 2)) / (double)env->height;
	return (0);
}
