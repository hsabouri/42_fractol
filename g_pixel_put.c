/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_pixel_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 16:46:14 by hsabouri          #+#    #+#             */
/*   Updated: 2017/01/04 15:39:59 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image					g_pixel_put(t_image image, int x, int y, t_color color)
{
	if (x < image.width && y < image.height && x >= 0 && y >= 0)
	{
		image.data[(x + (y * image.width)) * 4 + RED] = color.red;
		image.data[(x + (y * image.width)) * 4 + GRE] = color.gre;
		image.data[(x + (y * image.width)) * 4 + BLU] = color.blu;
	}
	return (image);
}

static unsigned char	g_pix_smooth(t_image img, int w, int h, int offc)
{
	int		av;
	int		wd;

	wd = img.width;
	av = img.data[(h * wd + w) * 4 + offc];
	av += ((w != 0) ? img.data[(h * wd + w - 1) * 4 + offc] : av);
	av += ((w != 0 && h != 0) ?
		img.data[((h - 1) * wd + w - 1) * 4 + offc] : av / 2);
	av += ((w != 0 && h != img.height - 1) ?
		img.data[((h + 1) * wd + w - 1) * 4 + offc] : av / 3);
	av += ((h != 0) ? img.data[((h - 1) * wd + w) * 4 + offc] : av / 4);
	av += ((h != img.height - 1) ?
		img.data[((h + 1) * wd + w) * 4 + offc] : av / 5);
	av += ((w != img.width - 1 && h != 0) ?
		img.data[((h - 1) * wd + w + 1) * 4 + offc] : av / 6);
	av += ((w != img.width - 1) ?
		img.data[((h) * wd + w + 1) * 4 + offc] : av / 7);
	av += ((w != img.width - 1 && h != img.height - 1) ?
		img.data[((h + 1) * wd + w + 1) * 4 + offc] : av / 8);
	return ((unsigned char)(av / 9));
}

t_image					g_epilepsie(t_image image)
{
	int		w;
	int		h;
	int		wd;

	wd = image.width;
	h = 0;
	while (h < image.height)
	{
		w = 0;
		while (w < image.width)
		{
			image.data[(wd * h + w) * 4 + RED] = g_pix_smooth(image, w, h, RED);
			image.data[(wd * h + w) * 4 + GRE] = g_pix_smooth(image, w, h, GRE);
			image.data[(wd * h + w) * 4 + BLU] = g_pix_smooth(image, w, h, BLU);
			w++;
		}
		h++;
	}
	return (image);
}

void					g_refresh_win(t_image image, t_env env)
{
	mlx_put_image_to_window(env.mlx, env.win, image.mlx_img, 0, 0);
}
