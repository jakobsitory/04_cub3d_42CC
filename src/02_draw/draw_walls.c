/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:03:31 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/25 19:29:56 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_pixel_color(t_ray_result ray, int y)
{
	float	rel_y;
	int		column;
	int		row;
	char	*color_hex_string;
	int		color_hex;

	if (is_whole_number(ray.x))
		rel_y = ray.y - (int)ray.y;
	else if (is_whole_number(ray.y))
		rel_y = ray.x - (int)ray.x;
	else
		rel_y = 0;
	if (((int)ray.degree <= 270 && (int)ray.degree >= 90) && \
	(is_whole_number(ray.y)))
		rel_y = 1 - rel_y;
	column = (ray.xpm->columns) * rel_y;
	row = ((float)(y - ray.start_y) / ray.line_height) * ray.xpm->rows;
	if (rel_y == 1)
		column--;
	color_hex_string = get_hex_from_char(ray.xpm->lines[row][column], ray.xpm);
	color_hex = hex_to_int(color_hex_string);
	return (color_hex);
}

void	draw_walls(t_data *data)
{
	int	x;
	int	y;
	int	color;
	int	y_range;

	x = -1;
	while (++x < WINDOW_W)
	{
		y = data->rays[x]->start_y;
		while (y < data->rays[x]->end_y && y < WINDOW_H)
		{
			color = get_pixel_color(*data->rays[x], y);
			y_range = (data->rays[x]->end_y - data->rays[x]->start_y) / 100;
			while (y_range-- >= 0 && y < WINDOW_H)
			{
				if (y <= WINDOW_H)
				{
					draw_pixel(data->window, x, y, color);
					if (SHADER)
						draw_shade(data->window, x, y, data->rays[x]->distance);
				}
				y++;
			}
		}
	}
}
