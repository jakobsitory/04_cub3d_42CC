/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:03:18 by jschott           #+#    #+#             */
/*   Updated: 2024/01/19 16:36:08 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

int	map_scale(int map_size[2])
{
	float	win_aspect;
	float	map_aspect;

	win_aspect = (float) WINDOW_W / (int) WINDOW_H;
	map_aspect = (float) map_size[0] / (float) map_size[1];
	if (win_aspect < map_aspect)
		return (WINDOW_W / map_size[0]);
	return (WINDOW_H / map_size[1]);
}

/* int	draw_ray(t_image *image, int start[2], int dist, int direction)
{
	return 0;
} */

int	draw_player(t_scene *scene)
{
	float	player_size;
	int		start[2];
	int		end[2];
	float		scale;
	
	scale = scene->map_scale;
	player_size = 0.1;
	start[0] = 2 + scale * scene->player_position[0] / scene->map_square_scale;
	start[1] = 2 + scale * scene->player_position[1] / scene->map_square_scale;
	end[0] = start[0];
	end[1] = start[1];
	start[0] -= 0.5 * player_size * scale;
	start[1] -= 0.5 * player_size * scale;
	end[0] += 0.5 * player_size * scale;
	end[1] += 0.5 * player_size * scale;
	rectangle_fill(scene->image, start, end, COLOR_MAP_PLAYER);
	return (0);
}

int	draw_map(t_scene *scene)
{
	int	start[2];
	int	end[2];
	int		x;
	int		y;

	start[0] = 1;
	start[1] = 1;
	end[0] = scene->map_scale;
	end[1] = scene->map_scale;
	x = -1;
	y = -1;
	while (++y < scene->map_size[1])
	{
		while (++x < scene->map_size[0])
		{
			if (scene->map[y][x] == '1')
				rectangle_fill(scene->image, start, end, COLOR_MAP_WALL);
			else
				rectangle_fill(scene->image, start, end, COLOR_MAP_FLOOR);
			start[0] += scene->map_scale;
			end[0] += scene->map_scale;
		}
		start[0] = 1;
		start[1] += scene->map_scale;
		end[0] = scene->map_scale;
		end[1] += scene->map_scale;
		x = -1;
	}
	draw_player(scene);
	draw_fov(scene->image, scene->rays, scene);
	return (0);
}
