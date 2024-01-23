/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:57:43 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/23 16:21:15 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_file(t_data *data, char *filepath)
{
	data->filepath = ft_strdup(filepath);
	parse_textures(data);
	parse_colors(data);
	parse_map(data);
	check_invalid_lines(data);
	parse_successful(data);
}

void	parse_textures(t_data *data)
{
	data->fd = open(data->filepath, O_RDONLY);
	data->line = get_next_line(data->fd);
	while (data->line)
	{
		if (ft_strncmp(data->line, NORTH_ID, 3) == 0)
			save_identifier(NORTH_ID, data->line, data);
		else if (ft_strncmp(data->line, SOUTH_ID, 3) == 0)
			save_identifier(SOUTH_ID, data->line, data);
		else if (ft_strncmp(data->line, WEST_ID, 3) == 0)
			save_identifier(WEST_ID, data->line, data);
		else if (ft_strncmp(data->line, EAST_ID, 3) == 0)
			save_identifier(EAST_ID, data->line, data);
		else if (ft_strncmp(data->line, "", 0) != 0)
			break ;
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	free(data->line);
	close(data->fd);
}

void	parse_colors(t_data *data)
{
	char	*line;

	data->fd = open(data->filepath, O_RDONLY);
	line = get_next_line(data->fd);
	while (line)
	{
		if (ft_strncmp(line, FLOOR_ID, 2) == 0)
			save_color(FLOOR_ID, line, data);
		else if (ft_strncmp(line, CEILING_ID, 2) == 0)
			save_color(CEILING_ID, line, data);
		else if (ft_strncmp(line, "", 0) != 0)
			break ;
		free(line);
		line = get_next_line(data->fd);
	}
	free(line);
	check_hex_range(data);
	data->res->floor_hex = convert_to_hex(data->res->floor_colors);
	data->res->ceiling_hex = convert_to_hex(data->res->ceiling_colors);
	close (data->fd);
}

void	parse_map(t_data *data)
{
	read_map(data);
	get_player_pos(data);
	get_player_orientation(data);
	check_map(data);
}

void	check_invalid_lines(t_data *data)
{
	data->fd = open(data->filepath, O_RDONLY);
	data->line = get_next_line(data->fd);
	while (data->line)
	{
		if (ft_strncmp(data->line, NORTH_ID, 3) == 0 || 
			ft_strncmp(data->line, SOUTH_ID, 3) == 0 || 
			ft_strncmp(data->line, WEST_ID, 3) == 0 || 
			ft_strncmp(data->line, EAST_ID, 3) == 0 || 
			ft_strncmp(data->line, CEILING_ID, 2) == 0 || 
			ft_strncmp(data->line, FLOOR_ID, 2) == 0 || 
			ft_strncmp(data->line, "\n", 1) == 0)
		{
		}
		else if (only_spaces(data->line) == 1)
			exit_error(ONLY_SPACES, data);
		else if (is_valid_map_line(data->line) == 1)
			break ;
		else
			exit_error(INV_LINE, data);
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	free(data->line);
	data->line = NULL;
	close(data->fd);
}
