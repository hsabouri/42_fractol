/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_pixel_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:46:14 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/02 19:04:27 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		g_pixel_put(t_image image, int x, int y, t_color color)
{
	if (x < image.width && y < image.height && x >= 0 && y >= 0)
	{
		image.data[(x + (y * image.width)) * 4 + RED] = color.red;
		image.data[(x + (y * image.width)) * 4 + GRE] = color.gre;
		image.data[(x + (y * image.width)) * 4 + BLU] = color.blu;
	}
	return (image);
}

void		gs_pixel_put(t_image *image, int x, int y, t_color color)
{
	if (x < image->width && y < image->height && x >= 0 && y >= 0)
	{
		image->data[(x + (y * image->width)) * 4 + RED] = color.red;
		image->data[(x + (y * image->width)) * 4 + GRE] = color.gre;
		image->data[(x + (y * image->width)) * 4 + BLU] = color.blu;
	}
}

void		g_refresh_win(t_image image, t_env env)
{
	mlx_put_image_to_window(env.mlx, env.win, image.mlx_img, 0, 0);
}
