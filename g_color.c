/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:55:35 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/20 15:23:26 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color			*gradient_maker(t_color *gradient, t_env env)
{
	if (env.cscheme == PASTEL)
	{
		gradient[0] = (t_color){62, 0, 12};
		gradient[1] = (t_color){124, 11, 43};
		gradient[2] = (t_color){251, 75, 78};
		gradient[3] = (t_color){124, 11, 43};
		gradient[4] = (t_color){62, 12, 17};
	}
	else if (env.cscheme == BURNING)
	{
		gradient[0] = (t_color){0, 0, 0};
		gradient[1] = (t_color){127, 0, 21};
		gradient[2] = (t_color){255, 0, 43};
		gradient[3] = (t_color){255, 127, 43};
		gradient[4] = (t_color){255, 255, 43};
	}
	else
	{
		gradient[0] = (t_color){0, 7, 100};
		gradient[1] = (t_color){32, 107, 203};
		gradient[2] = (t_color){237, 255, 255};
		gradient[3] = (t_color){255, 170, 0};
		gradient[4] = (t_color){0, 2, 0};
	}
	return (gradient);
}

t_color			color_gradient(int i, t_env env, t_color *grad, float *position)
{
	int		pos;
	float	ir;
	float	ig;
	float	ib;
	t_color new;

	pos = 0;
	while (pos < 4 && i > env.colormod * position[pos + 1])
		pos++;
	ir = ((float)grad[pos + 1].red - grad[pos].red) /
		(env.colormod * position[pos + 1] - env.colormod * position[pos]);
	ig = ((float)grad[pos + 1].gre - grad[pos].gre) /
		(env.colormod * position[pos + 1] - env.colormod * position[pos]);
	ib = ((float)grad[pos + 1].blu - grad[pos].blu) /
		(env.colormod * position[pos + 1] - env.colormod * position[pos]);
	new.red = grad[pos].red + (i - env.colormod * position[pos]) * ir;
	new.gre = grad[pos].gre + (i - env.colormod * position[pos]) * ig;
	new.blu = grad[pos].blu + (i - env.colormod * position[pos]) * ib;
	return (new);
}
t_color 		color_wheel(int i, t_env env)
{
	t_color	gradient[5];
	float	position[5];
	t_color	new;
	
	if (i == -1)
	{
		new.red = 0;
		new.gre = 0;
		new.blu = 0;
		return (new);
	}
	i = i % env.colormod;
	gradient_maker(gradient, env);
	position[0] = 0;
	position[1] = 0.26;
	position[2] = 0.52;
	position[3] = 0.7425;
	position[4] = 1;
	new = color_gradient(i, env, gradient, position);
	return (new);
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
