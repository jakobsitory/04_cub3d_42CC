/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:56 by jschott           #+#    #+#             */
/*   Updated: 2024/01/18 12:34:14 by jschott          ###   ########.fr       */
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
	scale = scene->map_scale / scene->map_square_scale;
	start[0] = scene->player_position[0] * scale;
	start[1] = scene->player_position[1] * scale;
	while (i < WINDOW_W)
	{
		end[0] = rays[i]->x * scale;
		end[1] = rays[i]->y * scale;
		draw_line(image, start, end, COLOR_MAP_FOV);
		i++;
	}
	return (0);
}
