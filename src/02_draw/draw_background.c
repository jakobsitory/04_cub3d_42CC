/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:12:27 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 13:02:17 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Draws a single pixel at the specified coordinates with the given color.
 * 
 * @param window Pointer to the t_window structure containing window and image information.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @param color The color of the pixel.
 */
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

/**
 * Draws a rectangle on the window by filling in pixels between start and end coordinates with the specified color.
 * 
 * @param window Pointer to the t_window structure containing window and image information.
 * @param start Array of two integers specifying the starting x and y coordinates.
 * @param end Array of two integers specifying the ending x and y coordinates.
 * @param color The color to fill the rectangle with.
 */
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

/**
 * Fills the entire window background with a color specified for each pixel, based on the environment settings.
 * 
 * @param window Pointer to the t_window structure containing window and image information.
 * @param env Pointer to the t_env structure containing environment settings, including the background color array.
 */
void	draw_background(t_window *window, t_env *env)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (++y < WINDOW_H)
	{
		while (++x < WINDOW_W)
			draw_pixel(window, x, y, env->background_hex[y * WINDOW_W + x]);
		x = -1;
	}
}
