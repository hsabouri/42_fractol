/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_fract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:13:17 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/04 14:35:22 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia(double zx, double zy, t_env env)
{
	int		i;
	double	newx;

	i = 0;
	while (i < env.iter)
	{
		newx = zx * zx - zy * zy + env.jx;
		zy = 2 * zx * zy + env.jy;
		zx = newx;
		if (zx * zx + zy * zy >= 4)
			return (i);
		i++;
	}
	return (-1);
}

int		mandelbrot(double cx, double cy, int iteration)
{
	int		i;
	double	zx;
	double	zy;
	double	newx;

	i = 0;
	zx = 0;
	zy = 0;
	while (i < iteration)
	{
		newx = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = newx;
		if (zx * zx + zy * zy >= 4)
			return (i);
		i++;
	}
	return (-1);
}

int		burningship(double cx, double cy, int iteration)
{
	int		i;
	double	zx;
	double	zy;
	double	newx;

	i = 0;
	zx = 0;
	zy = 0;
	while (i < iteration)
	{
		zx = ABS(zx);
		zy = ABS(zy);
		newx = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = newx;
		if (zx * zx + zy * zy >= 4)
			return (i);
		i++;
	}
	return (-1);
}
