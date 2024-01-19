/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:56 by jschott           #+#    #+#             */
/*   Updated: 2024/01/19 16:39:12 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

int	draw_fov(t_image *image, t_ray_result **rays, t_scene *scene)
{
	int		start[2];
	int		end[2];
	int		i;
	float	scale;

	i = 0;
	scale = 10 * scene->map_scale / scene->map_square_scale;
	start[0] = scene->player_position[0] * scale / 10;
	start[1] = scene->player_position[1] * scale / 10;
	end[0] = rays[i]->x * scale;
	end[1] = rays[i]->y * scale;
	while (i < WINDOW_W)
	{
		if (rays[i]->x * scale != end[0] || rays[i]->y * scale != end[1])
		{
			end[0] = rays[i]->x * scale;
			end[1] = rays[i]->y * scale;
			draw_line(image, start, end, COLOR_MAP_FOV);
		}
		i++;
	}
	return (0);
}
