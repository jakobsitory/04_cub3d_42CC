/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:44:18 by jschott           #+#    #+#             */
/*   Updated: 2024/01/25 19:17:33 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_transp_pixel(unsigned int *background, int x, int y, int color)
{
	unsigned int	dst_color;
	unsigned int	alpha;
	unsigned int	old_rgb[3];
	unsigned int	new_rgb[3];

	if (x >= 0 && y >= 0 && y <= WINDOW_H && x <= WINDOW_W)
	{
		dst_color = background[y * WINDOW_W + x];
		alpha = (color >> 24) & 0xFF;
		old_rgb[0] = (color >> 16) & 0xFF;
		old_rgb[1] = (color >> 8) & 0xFF;
		old_rgb[2] = color & 0xFF;
		new_rgb[0] = (alpha * old_rgb[0] + (255 - alpha) \
						* ((dst_color >> 16) & 0xFF)) / 255;
		new_rgb[1] = (alpha * old_rgb[1] + (255 - alpha) \
						* ((dst_color >> 8) & 0xFF)) / 255;
		new_rgb[2] = (alpha * old_rgb[2] + (255 - alpha) \
						* (dst_color & 0xFF)) / 255;
		background[y * WINDOW_W + x] = (alpha << 24) | (new_rgb[0] << 16) | \
										(new_rgb[1] << 8) | new_rgb[2];
	}
}

void	render_shader(unsigned int	*background, int x, int y)
{
	int		color;
	int		alpha;
	float	distance;

	if (y <= WINDOW_H / 2)
		distance = (float)(20 * y) / (float)(WINDOW_H - 70);
	else
		distance = 20.0f - ((float)(20 * y + 35) / (float)(WINDOW_H));
	color = COLOR_SHADOW;
	if (distance >= PLAYER_VIEW_DISTANCE)
		background[y * WINDOW_W + x] = color;
	alpha = (int)(255 * distance / (float) PLAYER_VIEW_DISTANCE);
	color = color | (alpha << 24);
	render_transp_pixel(background, x, y, color);
}

void	render_background(t_env *env)
{
	int				x;
	int				y;
	int				color;

	x = -1;
	y = -1;
	color = env->ceiling_hex;
	while (++y < WINDOW_H)
	{
		if (y == WINDOW_H / 2)
			color = env->floor_hex;
		while (++x < WINDOW_W)
			env->background_hex[y * WINDOW_W + x] = color;
		x = -1;
	}
	y = -1;
	while (SHADER && ++y < WINDOW_H)
	{
		while (++x < WINDOW_W)
			render_shader(env->background_hex, x, y);
		x = -1;
	}
}
