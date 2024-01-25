/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:18:32 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/25 16:44:20 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	read_map(t_data *data)
{
	char	*tmp;

	data->parser->fd = open(data->parser->filepath, O_RDONLY);
	data->parser->line = get_next_line(data->parser->fd);
	while (data->parser->line)
	{
		while (!is_valid_map_line(data->parser->line))
		{
			free(data->parser->line);
			data->parser->line = get_next_line(data->parser->fd);
		}
		while (data->parser->line)
		{
			tmp = ft_strdup(data->parser->map_string);
			free(data->parser->map_string);
			data->parser->map_string = ft_strjoin(tmp, data->parser->line);
			free(tmp);
			free(data->parser->line);
			data->parser->line = get_next_line(data->parser->fd);
		}
		calc_map_size(data);
		data->env->map = create_map_arr(data, 0, 0, 0);
		data->parser->map_copy = create_map_arr(data, 0, 0, 0);
	}
}

void	get_player_orientation(t_data *data)
{
	if (data->env->map[(int)data->env->player_position[1]] \
	[(int)data->env->player_position[0]] == 'N')
		data->env->player_orientation = 0;
	else if (data->env->map[(int)data->env->player_position[1]] \
	[(int)data->env->player_position[0]] == 'E')
		data->env->player_orientation = 90;
	else if (data->env->map[(int)data->env->player_position[1]] \
	[(int)data->env->player_position[0]] == 'S')
		data->env->player_orientation = 180;
	else if (data->env->map[(int)data->env->player_position[1]] \
	[(int)data->env->player_position[0]] == 'W')
		data->env->player_orientation = 270;
}

void	get_player_pos(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	y = 0;
	map = data->env->map;
	while (y < data->env->map_size[1])
	{
		while (x < data->env->map_size[0])
		{
			if (map[y][x] == 'N' || map[y][x] == 'E' \
			|| map[y][x] == 'S' || map[y][x] == 'W')
			{
				data->env->player_position[0] = x;
				data->env->player_position[1] = y;
				break ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}
