/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsabouri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:36:01 by hsabouri          #+#    #+#             */
/*   Updated: 2016/12/14 16:39:22 by hsabouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error(int code)
{
	if (code == EXIT)
	{
		ft_putendl("Closing...");
		exit(EXIT_SUCCESS);
	}
	if (code == USAGE)
		ft_putendl("usage: ./fractol fractal_name");
	if (code == MALLOC)
		ft_putendl("\x1b[31mFailed to allocate memory.\x1b[0m");
	if (code == FEXIST)
		ft_putendl("\x1b[31mFractal does not exist.\x1b[0m");
	exit(EXIT_FAILURE);
}
