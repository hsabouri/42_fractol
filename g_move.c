/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:27:03 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/20 11:23:50 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	g_zoom(t_env env, double coef)
{
	env.coefx *= 4 * coef / (double)env.width;
	env.coefy *= 4 * coef / (double)env.height;
	env.offsetx = env.offsetx / env.coefx;
	env.offsetx = env.offsetx / env.coefx;
	return (env);
}
