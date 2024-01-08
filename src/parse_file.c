/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:57:43 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/08 20:05:49 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_file(t_data *data, char *filepath)
{
	data->res = malloc(sizeof(t_res));
	if (!data->res)
		exit_error(MALLOC_ERR, data);
	data->filepath = ft_strdup(filepath);
	parse_textures(data);
	parse_colors(data);
}

void	parse_textures(t_data *data)
{
	char *line;

	data->fd = open(data->filepath, O_RDONLY);
	line = get_next_line(data->fd);
	while (line)
	{
		if (ft_strncmp(line, NORTH_ID, 3) == 0)
			save_identifier(NORTH_ID , line, data);
		else if (ft_strncmp(line, SOUTH_ID, 3) == 0)
			save_identifier(SOUTH_ID , line, data);
		else if (ft_strncmp(line, WEST_ID, 3) == 0)
			save_identifier(WEST_ID , line, data);
		else if (ft_strncmp(line, EAST_ID, 3) == 0)
			save_identifier(EAST_ID , line, data);
		else if (ft_strncmp(line, "", 0) != 0)
			break ;
		free(line);
		line = get_next_line(data->fd);
	}
	free(line);
	close(data->fd);
}

void	parse_colors(t_data *data)
{
	char *line;

	data->fd = open(data->filepath, O_RDONLY);
	line = get_next_line(data->fd);
	while (line)
	{
		if (ft_strncmp(line, FLOOR_ID, 2) == 0)
			save_color(FLOOR_ID, line, data);
		else if (ft_strncmp(line, CEILING_ID, 2) == 0)
			save_color(CEILING_ID , line, data);
		else if (ft_strncmp(line, "", 0) != 0)
			break ;
		free(line);
		line = get_next_line(data->fd);
	}
	free(line);
	check_hex_range(data);
	close (data->fd);
}

void	save_color(char *identifier, char *line, t_data *data)
{
	char *line_trimmed;
	char *line_trimmed_whitesp;

	line += ft_strlen(identifier);
	line_trimmed = ft_strtrim(line, "\n");
	while (*line == ' ')
		line++;
	valid_number_format(line_trimmed, data);
	line_trimmed_whitesp = remove_whitespace(line_trimmed, data);
	free(line_trimmed);
	valid_chars_color(line, data);
	if (ft_strncmp(identifier, CEILING_ID, ft_strlen(identifier)) == 0)
		save_next_hex(line_trimmed_whitesp, data->res->ceiling_colors, data);
	else if (ft_strncmp(identifier, FLOOR_ID, ft_strlen(identifier)) == 0)
		save_next_hex(line_trimmed_whitesp, data->res->floor_colors, data);
	free(line_trimmed_whitesp);
}