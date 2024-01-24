/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:12:27 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 16:11:12 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_pixel(t_window *window, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && y <= WINDOW_H && x <= WINDOW_W)
	{
		dst = window->img_addr + (y * window->img_line_length + \
							x * (window->img_bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_rectangle(t_window *window, int start[2], int end[2], int color)
{
	int	x;
	int	y;

	x = start[0] - 1;
	y = start[1] - 1;
	while (++y < end[1])
	{
		while (++x < end[0])
			draw_pixel(window, x, y, color);
		x = start[0] - 1;
	}
}

void	draw_background(t_window *window, t_env *env)
{
	int		x;
	int		y;
	int		color;
	float	distance;

	x = -1;
	y = -1;
	color = env->ceiling_hex;
	while (++y < WINDOW_H)
	{
		if (y == WINDOW_H / 2)
			color = env->floor_hex;
		if (y <= WINDOW_H / 2)
			distance = (float)(20 * y) / (float)(WINDOW_H - 70);
		else if (y >= WINDOW_H / 2)
			distance = 20.0f - ((float)(20 * y + 35) / (float)(WINDOW_H));

		while (++x < WINDOW_W)
		{
			draw_pixel(window, x, y, color);
			// draw_shader(scene->image, x, y, distance);
		}
		x = -1;
	}
}
