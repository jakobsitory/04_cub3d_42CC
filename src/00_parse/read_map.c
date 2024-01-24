/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:55:31 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/24 17:46:26 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**create_map_arr(t_data *data, int i, int j, int k)
{
	char	**map;

	map = init_map(data);
	while (data->parser->map_string[i])
	{
		if (data->parser->map_string[i] == '\n')
		{
			while (k < data->env->map_size[0])
				map[j][k++] = '-';
			map[j++][k] = '\0';
			k = 0;
		}
		else
		{
			if (data->parser->map_string[i] == ' ')
				map[j][k++] = '-';
			else
				map[j][k++] = data->parser->map_string[i];
		}
		i++;
	}
	while (k < data->env->map_size[0])
		map[j][k++] = '-';
	map[j][k] = '\0';
	return (map);
}

int	is_valid_map_line(char *line)
{
	int	i;

	i = 0;
	if (ft_strncmp(line, "\n", 1) == 0)
		return (0);
	while (line[i] == '1' || line[i] == '0' || line[i] == ' ' \
	|| line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (1);
	return (0);
}

void	calc_map_size(t_data *data)
{
	calc_no_lines(data);
	calc_line_length(data);
}

void	calc_no_lines(t_data *data)
{
	int	i;
	int	lines;

	lines = 0;
	i = 0;
	lines++;
	while (data->parser->map_string[i])
	{
		if (data->parser->map_string[i] == '\n')
			lines++;
		i++;
	}
	data->env->map_size[1] = lines;
}

void	calc_line_length(t_data *data)
{
	int	i;
	int	current_line_length;

	i = 0;
	current_line_length = 0;
	data->env->map_size[0] = 0;
	while (data->parser->map_string[i])
	{
		if (data->parser->map_string[i] == '\n')
		{
			if (current_line_length > data->env->map_size[0])
				data->env->map_size[0] = current_line_length;
			current_line_length = 0;
		}
		else
			current_line_length++;
		i++;
	}
	if (current_line_length > data->env->map_size[0])
		data->env->map_size[0] = current_line_length;
}
