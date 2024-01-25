/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_shader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 09:47:49 by jschott           #+#    #+#             */
/*   Updated: 2024/01/25 11:59:54 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define VIEW_DISTANCE	10
#define COLOR_SHADOW	0x001B2029

void	my_transparent_pixel_put(t_window *window, int x, int y, int color)
{
	char *dst;

	if (x >= 0 && y >= 0 && y <= WINDOW_H && x <= WINDOW_W)
	{
		dst = window->img_addr + (y * window->img_line_length + \
				x * (window->img_bits_per_pixel / 8));
		unsigned int *dst_color = (unsigned int *)dst;
		unsigned int alpha = (color >> 24) & 0xFF;
		unsigned int red = (color >> 16) & 0xFF;
		unsigned int green = (color >> 8) & 0xFF;
		unsigned int blue = color & 0xFF;
		unsigned int new_red = (alpha * red + (255 - alpha) * ((*dst_color >> 16) & 0xFF)) / 255;
		unsigned int new_green = (alpha * green + (255 - alpha) * ((*dst_color >> 8) & 0xFF)) / 255;
		unsigned int new_blue = (alpha * blue + (255 - alpha) * (*dst_color & 0xFF)) / 255;
		*dst_color = (alpha << 24) | (new_red << 16) | (new_green << 8) | new_blue;
    }
}

void	draw_shader(t_window *window, int x, int y, float distance)
{
	if (distance >= VIEW_DISTANCE)
		draw_pixel(window, x, y, COLOR_SHADOW);
	int alpha = (int)(255 * distance / (float) VIEW_DISTANCE);
	int color = COLOR_SHADOW;
	color = color | (alpha << 24);
	my_transparent_pixel_put(window, x, y, color);
}