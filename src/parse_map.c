/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:18:32 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/22 10:44:44 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

void	read_map(t_data *data)
{
	char	*tmp;

	data->fd = open(data->filepath, O_RDONLY);
	data->line = get_next_line(data->fd);
	while (data->line)
	{
		while (!is_valid_map_line(data->line))
		{
			free(data->line);
			data->line = get_next_line(data->fd);
		}
		while (data->line)
		{
			tmp = ft_strdup(data->map->map_string);
			free(data->map->map_string);
			data->map->map_string = ft_strjoin(tmp, data->line);
			free(tmp);
			free(data->line);
			data->line = get_next_line(data->fd);
		}
		calc_map_size(data->map);
		data->map->map = create_map_arr(data, 0, 0, 0);
		data->map->map_copy = create_map_arr(data, 0, 0, 0);
	}
}

void	get_player_orientation(t_data *data)
{
	if (data->map->map[data->map->player_position[1]] \
	[data->map->player_position[0]] == 'N')
		data->map->player_orientation = 0;
	else if (data->map->map[data->map->player_position[1]] \
	[data->map->player_position[0]] == 'E')
		data->map->player_orientation = 90;
	else if (data->map->map[data->map->player_position[1]] \
	[data->map->player_position[0]] == 'S')
		data->map->player_orientation = 180;
	else if (data->map->map[data->map->player_position[1]] \
	[data->map->player_position[0]] == 'W')
		data->map->player_orientation = 270;
}

void	get_player_pos(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	y = 0;
	map = data->map->map;
	while (y < data->map->map_size[1])
	{
		while (x < data->map->map_size[0])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E' \
			|| map[y][x] == 'S' || map[y][x] == 'W')
			{
				data->map->player_position[0] = x;
				data->map->player_position[1] = y;
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
