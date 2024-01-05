/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:03:18 by jschott           #+#    #+#             */
/*   Updated: 2024/01/05 16:43:22 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

int	map_scale(int map_size[2])
{
	float	win_aspect;
	float	map_aspect;

	win_aspect = (float) WIN_WIDTH / (int) WIN_HEIGHT;
	map_aspect = (float) map_size[0] / (float) map_size[1];
	if(win_aspect < map_aspect)
		return (WIN_WIDTH / map_size[0]);
	return (WIN_HEIGHT / map_size[1]);
}

/* int	draw_ray(t_image *image, int start[2], int dist, int direction)
{
	return 0;
} */

int	draw_player(t_scene *scene)
{
	int		scale;
	float	player_size;
	int		start[2];
	int		end[2];

	player_size = 0.4;
	scale = 0.5 * map_scale(scene->map_size);
	start[0] = 1 + scale * scene->player_position[0] + scale * player_size;
	start[1] = 1 + scale * scene->player_position[1] + scale * player_size;
	end[0] = (scale * scene->player_position[0] + scale) - scale * player_size;
	end[1] = (scale * scene->player_position[1] + scale) - scale * player_size;
	rectangle_fill(scene->image, start, end, 0xFF0000);
	return (0);
}

int	draw_map(t_scene *scene)
{
	int	start[2];
	int	end[2];
	int	x;
	int	y;
	int	scale;

	scale = 0.5 * map_scale(scene->map_size);
	start[0] = 1;
	start[1] = 1;
	end[0] = scale;
	end[1] = scale;
	x = -1;
	y = -1;
	while(++y < scene->map_size[1])
	{
		while(++x < scene->map_size[0])
		{
			if (scene->map[y][x] == 1)
				rectangle_fill(scene->image, start, end, 0x000000);
			else
				rectangle_fill(scene->image, start, end, 0xFFFFFF);
			start[0] += scale;
			end[0] += scale;
		}
		start[0] = 1;
		start[1] += scale;
		end[0] = scale;
		end[1] += scale;
		x = -1;
	}
	draw_player(scene);
	return (0);
}
