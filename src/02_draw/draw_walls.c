/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/01/24 19:28:10 by lgrimmei         ###   ########.fr       */
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
	printf("rely: %f columns %i\n", rel_y, ray.xpm->columns);
	column = (ray.xpm->columns - 1) * rel_y;
	row = ((float)(y - ray.start_y) / ray.line_height) * ray.xpm->rows;
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

	x = 0;
	while (x < WINDOW_W)
	{
		y = data->rays[x]->start_y;
		while (y < data->rays[x]->end_y)
		{
			color = get_pixel_color(*data->rays[x], y);
			y_range = (data->rays[x]->end_y - data->rays[x]->start_y) / 100;
			while (y_range >= 0)
			{
				draw_pixel(data->window, x, y, color);
				//draw_shader(data->window, x, y, data->rays[x]->distance);
				y++;
				y_range--;
			}
		}
		y = 0;
		x++;
	}
}
