/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:03:18 by jschott           #+#    #+#             */
/*   Updated: 2024/01/25 15:57:14 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	map_scale(int map_size[2])
{
	float	win_aspect;
	float	map_aspect;
	int		scale;

	win_aspect = (float) WINDOW_W / (int) WINDOW_H;
	map_aspect = (float)(map_size[0] - 1) / (float)(map_size[1] - 1);
	if (win_aspect < map_aspect)
		scale = MINIMAP_SIZE * (WINDOW_W / (map_size[0] - 1));
	else
		scale = MINIMAP_SIZE * (WINDOW_H / (map_size[1] - 1));
	return (scale);
}

int	draw_fov(t_window *window, t_ray_result **rays, t_env *env)
{
	int		start[2];
	int		end[2];
	int		i;
	float	scale;

	i = 0;
	scale = env->map_scale;
	start[0] = env->player_position[0] * scale;
	start[1] = env->player_position[1] * scale;
	end[0] = rays[i]->x * scale;
	end[1] = rays[i]->y * scale;
	while (i < WINDOW_W)
	{
		if ((int)(rays[i]->x * scale) != end[0] \
			|| (int)(rays[i]->y * scale) != end[1])
		{
			end[0] = rays[i]->x * scale;
			end[1] = rays[i]->y * scale;
			draw_line(window, start, end, COLOR_MAP_PLAYER);
		}
		i++;
	}
	return (0);
}

int	draw_player(t_window *window, t_env *env)
{
	int		start[2];
	int		end[2];
	float	scale;

	scale = env->map_scale;
	start[0] = scale * env->player_position[0];
	start[1] = scale * env->player_position[1];
	end[0] = start[0];
	end[1] = start[1];
	start[0] -= 0.5 * PLAYER_SIZE * scale;
	start[1] -= 0.5 * PLAYER_SIZE * scale;
	end[0] += 0.5 * PLAYER_SIZE * scale;
	end[1] += 0.5 * PLAYER_SIZE * scale;
	draw_rectangle(window, start, end, COLOR_MAP_PLAYER);
	return (0);
}

void	draw_floor(t_window *window, t_env *env)
{
	int	start[2];
	int	end[2];
	int	index[2];

	start[1] = 1;
	end[1] = env->map_scale;
	index[0] = -1;
	index[1] = -1;
	while (++index[1] < env->map_size[1])
	{
		start[0] = 1;
		end[0] = env->map_scale;
		while (++index[0] < env->map_size[0])
		{
			if (env->map[index[1]][index[0]] == '1')
				draw_rectangle(window, start, end, COLOR_MAP_WALL);
			else
				draw_rectangle(window, start, end, COLOR_MAP_FLOOR);
			start[0] += env->map_scale;
			end[0] += env->map_scale;
		}
		start[1] += env->map_scale;
		end[1] += env->map_scale;
		index[0] = -1;
	}
}

int	draw_map(t_data *data)
{
	draw_floor(data->window, data->env);
	draw_player(data->window, data->env);
	draw_fov(data->window, data->rays, data->env);
	return (0);
}
