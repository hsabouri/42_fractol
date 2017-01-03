/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:27:03 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/03 16:43:51 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	g_init_pos(t_env env)
{
	env.offsetx = env.width / 2;
	env.offsety = env.height / 2;
	env.coefx = 4 / (double)env.width;
	env.coefy = 4 / (double)env.height;
	env.zoom = 1;
	return (env);
}

t_env	g_move(t_env env, double x, double y)
{
	env.offsetx += x * (2 * env.coefx * env.width / 4) * env.width / 4;
	env.offsety += y * (2 * env.coefy * env.height / 4) * env.height / 4;
	return (env);
}

t_env	g_zoom(t_env env, double coef)
{
	env.coefx *= coef;
	env.coefy *= coef;
	return (env);
}
