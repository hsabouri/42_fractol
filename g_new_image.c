/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_new_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:13:45 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/14 16:39:08 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image		g_new_image(t_env env)
{
	t_image	new;

	new.mlx_img = mlx_new_image(env.mlx, env.width, env.height);
	new.data = mlx_get_data_addr(new.mlx_img, &new.bpp, &new.sl, &new.endian);
	new.width = env.width;
	new.height = env.height;
	return (new);
}
