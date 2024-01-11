/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:55:31 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/11 16:35:17 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	**create_map_arr(t_data *data, int i, int j, int k)
{
	char **map;

	map = init_map(data);
	while (data->map->map_string[i])
	{
		if (data->map->map_string[i] == '\n')
		{
			while (k < data->map->map_size[0])
				map[j][k++] = '-';
			map[j++][k] = '\0';
			k = 0;
		}
		else
		{
			if (data->map->map_string[i] == ' ')
				map[j][k++] = '-';
			else
				map[j][k++] = data->map->map_string[i];
		}
		i++;
	}
	while (k < data->map->map_size[0])
		map[j][k++] = '-';
	map[j][k] = '\0';
	return (map);
}

char	**init_map(t_data *data)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * (data->map->map_size[1] + 1));
	if (!map)
		exit_error(MALLOC_ERR, data);
	while (i < data->map->map_size[1])
	{
		map[i] = malloc(sizeof(char) * (data->map->map_size[0] + 1));
		if (!map[i])
			exit_error(MALLOC_ERR, data);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	is_valid_map_line(char *line)
{
	int	i;

	i = 0;
	if (ft_strncmp(line, "\n", 1) == 0)
		return (0);
	while (line[i] == '1' || line[i] == '0' || line[i] == ' ' || line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		i++;
	if (line[i] == '\0'|| line[i] == '\n')
		return (1);
	return (0);
}

void	calc_map_size(t_map *map)
{
	calc_no_lines(map);
	calc_line_length(map);
}

void calc_no_lines(t_map *map)
{
	int	i;
	int	lines;

	lines = 0;
	i = 0;
	lines++;
	while (map->map_string[i])
	{
		if (map->map_string[i] == '\n')
			lines++;
		i++;
	}
	map->map_size[1] = lines;
}

void calc_line_length(t_map *map)
{
	int i;
	int current_line_length;

	i = 0;
	current_line_length = 0;
	map->map_size[0] = 0;
	while (map->map_string[i])
	{
		if (map->map_string[i] == '\n')
		{
			if (current_line_length > map->map_size[0])
				map->map_size[0] = current_line_length;
			current_line_length = 0;
		}
		else
			current_line_length++;
		i++;
	}
	if (current_line_length > map->map_size[0])
		map->map_size[0] = current_line_length;
}

