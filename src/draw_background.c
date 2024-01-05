/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:12:27 by jschott           #+#    #+#             */
/*   Updated: 2024/01/05 12:30:42 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

void	my_mlx_pixel_put(t_scene *scene, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && y <= WIN_HEIGHT && x <= WIN_HEIGHT)
	{
		dst = scene->image->addr + (y * scene->image->line_length + \
							x * (scene->image->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	background_fill(t_scene *scene)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	y = -1;
	color = COLOR_CEILING; // PLACEHOLDER
	while (++y < WIN_HEIGHT)
	{
		if (y == WIN_HEIGHT / 2)
			color = COLOR_FLOOR; // PLACEHOLDER
		while (++x < WIN_WIDTH)
			my_mlx_pixel_put(scene, x, y, COLOR_CEILING);
		x = -1;
	}
}
