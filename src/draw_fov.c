/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:56 by jschott           #+#    #+#             */
/*   Updated: 2024/01/19 17:02:01 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

int	draw_fov(t_scene *scene)
{
	int		start[2];
	int		end[2];
	int		i;
	float	scale;

	i = 0;
	scale = 10 * scene->map_scale / scene->map_square_scale;
	start[0] = scene->player_position[0] * scale / 10;
	start[1] = scene->player_position[1] * scale / 10;
	end[0] = scene->rays[i]->x * scale;
	end[1] = scene->rays[i]->y * scale;
	while (i < WINDOW_W)
	{
		if (scene->rays[i]->x * scale != end[0] || scene->rays[i]->y * scale != end[1])
		{
			end[0] = scene->rays[i]->x * scale;
			end[1] = scene->rays[i]->y * scale;
			draw_line(scene, start, end);
		}
		i++;
	}
	return (0);
}
