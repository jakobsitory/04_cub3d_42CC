/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:03:18 by jschott           #+#    #+#             */
/*   Updated: 2024/01/23 17:12:43 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_scale(int map_size[2])
{
	float	win_aspect;
	float	map_aspect;

	win_aspect = (float) WINDOW_W / (int) WINDOW_H;
	map_aspect = (float) (map_size[0] - 1)  / (float) (map_size[1] - 1);
	if (win_aspect < map_aspect)
		return (WINDOW_W / (map_size[0] - 1));
	return (WINDOW_H / (map_size[1] - 1));
}

int	draw_player(t_scene *scene)
{
	float	player_size;
	int		start[2];
	int		end[2];
	float	scale;

	scale = scene->map_scale;
	player_size = 0.1;
	start[0] = scale * scene->player_position[0];
	start[1] = scale * scene->player_position[1];
	end[0] = start[0];
	end[1] = start[1];
	start[0] -= 0.5 * player_size * scale;
	start[1] -= 0.5 * player_size * scale;
	end[0] += 0.5 * player_size * scale;
	end[1] += 0.5 * player_size * scale;
	rectangle_fill(scene->image, start, end, COLOR_MAP_PLAYER);
	return (0);
}

void	draw_floor(t_scene *scene)
{
	int	start[2];
	int	end[2];
	int	index[2];

	start[1] = 1;
	end[1] = scene->map_scale;
	index[0] = -1;
	index[1] = -1;
	while (++index[1] < scene->map_size[1])
	{
		start[0] = 1;
		end[0] = scene->map_scale;
		while (++index[0] < scene->map_size[0])
		{
			if (scene->map[index[1]][index[0]] == '1')
				rectangle_fill(scene->image, start, end, COLOR_MAP_WALL);
			else
				rectangle_fill(scene->image, start, end, COLOR_MAP_FLOOR);
			start[0] += scene->map_scale;
			end[0] += scene->map_scale;
		}
		start[1] += scene->map_scale;
		end[1] += scene->map_scale;
		index[0] = -1;
	}
}

int	draw_map(t_scene *scene)
{
	draw_floor(scene);
	draw_player(scene);
	draw_fov(scene);
	return (0);
}
