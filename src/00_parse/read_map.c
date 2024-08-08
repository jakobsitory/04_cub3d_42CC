/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:55:31 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/08/08 12:57:56 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * The `create_map_arr` function dynamically allocates and initializes a 2D array to represent the game map based on a string
 * containing the map layout. It replaces spaces in the map string with dashes to indicate empty spaces and ensures each row of
 * the map array is null-terminated. The function also pads rows with dashes to match the maximum width of the map.
 * 
 * @param data Pointer to the t_data structure containing game data and settings.
 * @param i Index for iterating over the map string.
 * @param j Row index for the map array.
 * @param k Column index for the current row in the map array.
 * @return A pointer to the 2D array representing the game map.
 */
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

/**
 * Checks if a line from the map string is valid based on the game's map criteria.
 * 
 * @param line The line from the map string to be validated.
 * @return 1 if the line is valid, 0 otherwise.
 */
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

/**
 * Calculates the dimensions of the game map (width and height) based on the map string and stores
 * these dimensions in the `map_size` array of the `t_env` structure within `t_data`.
 * 
 * @param data Pointer to the t_data structure containing game data and settings.
 */
void	calc_map_size(t_data *data)
{
	calc_no_lines(data);
	calc_line_length(data);
}

/**
 * Calculates the number of lines (height) in the map string and updates the `map_size[1]` value
 * in the `t_env` structure within `t_data`.
 * 
 * @param data Pointer to the t_data structure containing game data and settings.
 */
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

/**
 * Calculates the maximum line length (width) in the map string and updates the `map_size[0]`
 * value in the `t_env` structure within `t_data`. It iterates through the map string, tracking the length of each line and
 * updating the maximum length as needed.
 * 
 * @param data Pointer to the t_data structure containing game data and settings.
 */
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
