/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:38:39 by jschott           #+#    #+#             */
/*   Updated: 2024/01/22 15:48:22 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

# define BLACK 0xFFFFFF

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
		return (BLACK);
	column = roundf(ray.xpm->columns * rel_y);
	row = ((float)(y - ray.start_y) / ray.line_height) * 10;
	//printf("ray.y %f ray_x %f rel_y %f row %i column %i\n", ray.y, ray.x, rel_y, row, column);
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
		while (y < scene->rays[x]->end_y)
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