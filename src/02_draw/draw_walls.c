/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/01/23 18:29:36 by lgrimmei         ###   ########.fr       */
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
	column = ray.xpm->columns * rel_y;
	row = ((float)(y - ray.start_y) / ray.line_height) * ray.xpm->rows;
	color_hex_string = get_hex_from_char(ray.xpm->lines[row][column], ray.xpm);
	color_hex = hex_to_int(color_hex_string);
	return (color_hex);
}

void	draw_walls(t_scene *scene)
{
	int	x;
	int	y;
	int	color;
	int	y_range;

	x = 0;
	while (x < WINDOW_W)
	{
		y = scene->rays[x]->start_y;
		while (y < 0)
			++y;
		while (y < WINDOW_H && y < scene->rays[x]->end_y)
		{
			color = get_pixel_color(*scene->rays[x], y);
			y_range = (scene->rays[x]->end_y - scene->rays[x]->start_y) / 100;
			while (y_range > 0)
			{
				my_mlx_pixel_put(scene->image, x, y, color);
				y++;
				if (y > scene->rays[x]->end_y)
					break ;
				y_range--;
			}
		}
		y = 0;
		x++;
	}
}
