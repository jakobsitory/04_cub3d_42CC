/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:38:39 by jschott           #+#    #+#             */
/*   Updated: 2024/01/22 12:32:27 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

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
	row = ((float)(y - ray.start_y) / ray.line_height);
	color_hex_string = get_hex_from_char(ray.xpm->lines[row][column], ray.xpm);
	color_hex = hex_to_int(color_hex_string);
	return (color_hex);
}

void	draw_walls(t_scene *scene)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < WINDOW_W)
	{
		y = scene->rays[x]->start_y;
		while (y < scene->rays[x]->end_y)
		{
			color = get_pixel_color(*scene->rays[x], y);
			//printf("printing on pxl: %i, %i\n", x, y);
			my_mlx_pixel_put(scene->image, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
}