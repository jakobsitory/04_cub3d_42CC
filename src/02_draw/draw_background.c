/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:12:27 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 11:36:33 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && y <= WINDOW_H && x <= WINDOW_W)
	{
		dst = image->addr + (y * image->line_length + \
							x * (image->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	rectangle_fill(t_image *image, int start[2], int end[2], int color)
{
	int	x;
	int	y;

	x = start[0] - 1;
	y = start[1] - 1;
	while (++y < end[1])
	{
		while (++x < end[0])
			my_mlx_pixel_put(image, x, y, color);
		x = start[0] - 1;
	}
}

void	background_fill(t_scene *scene)
{
	int	x;
	int	y;
	int	color;
	float	distance = 0;

	x = -1;
	y = -1;
	color = COLOR_CEILING; // PLACEHOLDER
	while (++y < WINDOW_H)
	{
		if (y == WINDOW_H / 2)
			color = COLOR_FLOOR; // PLACEHOLDER
		if (y <= WINDOW_H / 2)
			distance = (float)(20 * y) / (float)(WINDOW_H - 70);
		else if (y >= WINDOW_H / 2)
			distance = 20.0f - ((float)(20 * y + 35) / (float)(WINDOW_H));

		while (++x < WINDOW_W)
		{
			my_mlx_pixel_put(scene->image, x, y, color);
			// draw_shader(scene->image, x, y, distance);
		}
		x = -1;
	}
}
