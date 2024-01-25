/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:47:49 by jschott           #+#    #+#             */
/*   Updated: 2024/01/25 19:31:38 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_transparent_pixel_put(t_window *window, int x, int y, int color)
{
	char			*dst;
	unsigned int	*dst_color;
	unsigned int	alpha;
	unsigned int	old_rgb[3];
	unsigned int	new_rgb[3];

	if (x >= 0 && y >= 0 && y <= WINDOW_H && x <= WINDOW_W)
	{
		dst = window->img_addr + (y * window->img_line_length + \
				x * (window->img_bits_per_pixel / 8));
		dst_color = (unsigned int *)dst;
		alpha = (color >> 24) & 0xFF;
		old_rgb[0] = (color >> 16) & 0xFF;
		old_rgb[1] = (color >> 8) & 0xFF;
		old_rgb[2] = color & 0xFF;
		new_rgb[0] = (alpha * old_rgb[0] + (255 - alpha) \
						* ((*dst_color >> 16) & 0xFF)) / 255;
		new_rgb[1] = (alpha * old_rgb[1] + (255 - alpha) \
						* ((*dst_color >> 8) & 0xFF)) / 255;
		new_rgb[2] = (alpha * old_rgb[2] + (255 - alpha) \
						* (*dst_color & 0xFF)) / 255;
		*dst_color = (alpha << 24) | (new_rgb[0] << 16) \
						| (new_rgb[1] << 8) | new_rgb[2];
	}
}

void	draw_shade(t_window *window, int x, int y, float distance)
{
	int	alpha;
	int	color;

	if (distance < 3)
		return ;
	if (distance >= PLAYER_VIEW_DISTANCE)
	{
		draw_pixel(window, x, y, COLOR_SHADOW);
		return ;
	}
	distance -= 3;
	alpha = (int)(255 * distance / (float)(PLAYER_VIEW_DISTANCE - 3));
	color = COLOR_SHADOW;
	color = color | (alpha << 24);
	my_transparent_pixel_put(window, x, y, color);
}
