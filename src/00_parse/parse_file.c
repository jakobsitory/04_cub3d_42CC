/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:57:43 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/01 21:00:46 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_file(t_data *data, char *filepath)
{
	data->parser->filepath = ft_strdup(filepath);
	parse_textures(data);
	parse_colors(data);
	parse_map(data);
	check_invalid_lines(data);
	parse_successful(data);
}

void	parse_textures(t_data *data)
{
	data->parser->fd = open(data->parser->filepath, O_RDONLY);
	data->parser->line = get_next_line(data->parser->fd);
	while (data->parser->line)
	{
		if (ft_strncmp(data->parser->line, NORTH_ID, 3) == 0)
			save_identifier(NORTH_ID, data->parser->line, data);
		else if (ft_strncmp(data->parser->line, SOUTH_ID, 3) == 0)
			save_identifier(SOUTH_ID, data->parser->line, data);
		else if (ft_strncmp(data->parser->line, WEST_ID, 3) == 0)
			save_identifier(WEST_ID, data->parser->line, data);
		else if (ft_strncmp(data->parser->line, EAST_ID, 3) == 0)
			save_identifier(EAST_ID, data->parser->line, data);
		else if (ft_strncmp(data->parser->line, "", 0) != 0)
			break ;
		free(data->parser->line);
		data->parser->line = get_next_line(data->parser->fd);
	}
	free(data->parser->line);
	data->env->wall_textures[0] = parse_xpm(data->parser->north_text_path, \
	data);
	data->env->wall_textures[1] = parse_xpm(data->parser->east_text_path, data);
	data->env->wall_textures[2] = parse_xpm(data->parser->south_text_path, \
	data);
	data->env->wall_textures[3] = parse_xpm(data->parser->west_text_path, data);
	close(data->parser->fd);
}

void	parse_colors(t_data *data)
{
	data->parser->fd = open(data->parser->filepath, O_RDONLY);
	data->parser->line = get_next_line(data->parser->fd);
	while (data->parser->line)
	{
		if (ft_strncmp(data->parser->line, FLOOR_ID, 2) == 0)
			save_color(FLOOR_ID, data->parser->line, data);
		else if (ft_strncmp(data->parser->line, CEILING_ID, 2) == 0)
			save_color(CEILING_ID, data->parser->line, data);
		else if (ft_strncmp(data->parser->line, "", 0) != 0)
			break ;
		free(data->parser->line);
		data->parser->line = get_next_line(data->parser->fd);
	}
	free(data->parser->line);
	check_hex_range(data);
	data->env->floor_hex = convert_to_hex(data->parser->floor_colors);
	data->env->ceiling_hex = convert_to_hex(data->parser->ceiling_colors);
	close (data->parser->fd);
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
	data->parser->fd = open(data->parser->filepath, O_RDONLY);
	data->parser->line = get_next_line(data->parser->fd);
	while (data->parser->line)
	{
		if (ft_strncmp(data->parser->line, NORTH_ID, 3) == 0 || 
			ft_strncmp(data->parser->line, SOUTH_ID, 3) == 0 || 
			ft_strncmp(data->parser->line, WEST_ID, 3) == 0 || 
			ft_strncmp(data->parser->line, EAST_ID, 3) == 0 || 
			ft_strncmp(data->parser->line, CEILING_ID, 2) == 0 || 
			ft_strncmp(data->parser->line, FLOOR_ID, 2) == 0 || 
			ft_strncmp(data->parser->line, "\n", 1) == 0)
		{
		}
		else if (only_spaces(data->parser->line) == 1)
			exit_error(ONLY_SPACES, data);
		else if (is_valid_map_line(data->parser->line) == 1)
			break ;
		else
			exit_error(INV_LINE, data);
		free(data->parser->line);
		data->parser->line = get_next_line(data->parser->fd);
	}
	free(data->parser->line);
	data->parser->line = NULL;
	close(data->parser->fd);
}
