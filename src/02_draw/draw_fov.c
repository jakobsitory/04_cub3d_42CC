/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:53:56 by jschott           #+#    #+#             */
/*   Updated: 2024/01/23 16:21:15 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	draw_fov(t_scene *scene)
{
	int		start[2];
	int		end[2];
	int		i;
	float	scale;

	i = 0;
	scale = scene->map_scale;
	start[0] = scene->player_position[0] * scale;
	start[1] = scene->player_position[1] * scale;
	end[0] = scene->rays[i]->x * scale;
	end[1] = scene->rays[i]->y * scale;
	while (i < WINDOW_W)
	{
		if ((int)(scene->rays[i]->x * scale) != end[0] \
			|| (int)(scene->rays[i]->y * scale) != end[1])
		{
			end[0] = scene->rays[i]->x * scale;
			end[1] = scene->rays[i]->y * scale;
			draw_line(scene, start, end);
		}
		i++;
	}
	return (0);
}
