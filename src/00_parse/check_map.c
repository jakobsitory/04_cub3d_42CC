/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:57:38 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/24 17:36:12 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map(t_data *data)
{
	if (!check_valid_chars(data->env->map, data))
		exit_error(CHARS_ERR, data);
	flood_fill(data, data->parser->map_copy, data->env->player_position[0] \
	, data->env->player_position[1]);
}

void	flood_fill(t_data *data, char **map, int x, int y)
{
	int	i;
	int	*x_moves;
	int	*y_moves;

	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	x_moves = create_possible_moves_x(data);
	y_moves = create_possible_moves_y(data);
	i = 0;
	if (x >= data->env->map_size[0] - 1|| y >= data->env->map_size[1] - 1 || !is_valid_pos(map, x, y))
	{
		free(x_moves);
		free(y_moves);
		exit_error(MAP_ERR, data);
	}
	map[y][x] = 'X';
	while (i < 8)
	{
		flood_fill(data, map, x + x_moves[i], y + y_moves[i]);
		i++;
	}
	free(x_moves);
	free(y_moves);
}

int	is_valid_pos(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'E' \
	|| map[y][x] == 'S' || map[y][x] == 'W')
		return (1);
	return (0);
}

int	check_valid_chars(char **map, t_data *data)
{
	int	x;
	int	y;
	int	flag;

	x = 0;
	y = 0;
	flag = 0;
	while (y < data->env->map_size[1])
	{
		while (x < data->env->map_size[0])
		{
			if (!is_valid_char(map[y][x]))
				return (0);
			if (map[y][x] == 'N' || map[y][x] == 'E' \
			|| map[y][x] == 'S' || map[y][x] == 'W')
				flag++;
			if (flag > 1)
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == '-' || c == 'N' \
	|| c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}
