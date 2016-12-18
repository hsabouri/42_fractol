/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:55:35 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/18 21:05:45 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color 		color_wheel(int i, t_env env)
{
	t_color	gradient[2];
	float	position[2];
	int		pos;

	position[0] = 0;
	gradient[0] = (t_color){255, 255, 255};
	position[1] = 1;
	gradient[1] = (t_color){0, 0, 0};
	pos = 0;
	while ()
	return (color);
}
/*
static	t_color	weird_interpole(t_color *gradient, float *position, int pos, int i, t_env env)
{
	t_color	new;
	float	delta;
	float	ir;
	float	ig;
	float	ib;

	delta = (position[pos + 1] * (float)env.iter) - (position[pos] * (float)env.iter);
	ir = (float)(gradient[pos + 1].red - gradient[pos].red) / delta;
	ig = (float)(gradient[pos + 1].gre - gradient[pos].gre) / delta;
	ib = (float)(gradient[pos + 1].blu - gradient[pos].blu) / delta;
	new.red = gradient[pos].red + ((float)i - (position[pos] * (float)env.iter)) * ir;
	new.gre = gradient[pos].gre + ((float)i - (position[pos] * (float)env.iter)) * ig;
	new.blu = gradient[pos].blu + ((float)i - (position[pos] * (float)env.iter)) * ib;
	return (new);
}

t_color 		weird_gradient(int i, t_env env)
{
	t_color	gradient[6];
	float	position[6];
	int		j;

	gradient[0] = (t_color){0, 7, 100};
	position[0] = 0;
	gradient[1] = (t_color){32, 107, 203};
	position[1] = 0.16;
	gradient[2] = (t_color){237, 255, 255};
	position[2] = 0.42;
	gradient[3] = (t_color){255, 170, 0};
	position[3] = 0.6425;
	gradient[4] = (t_color){0, 2, 0};
	position[4] = 0.8425;
	gradient[5] = (t_color){0, 0, 0};
	position[5] = 1;
	j = 4;
	while (j > 0 && i > position[j] * (float)env.iter)
		j--;
	return (color_interpole(gradient, position, j, i, env));
}
*/
