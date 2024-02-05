/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:12:26 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/01 20:55:41 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	save_text_if_empty(t_data *data, char *identifier, char *value)
{
	if (ft_strncmp(identifier, NORTH_ID, ft_strlen(identifier)) == 0)
	{
		if (data->parser->north_text_path != NULL)
			exit_error(MULTIPLE_TEXT, data);
		data->parser->north_text_path = ft_strdup(value);
	}
	else if (ft_strncmp(identifier, EAST_ID, ft_strlen(identifier)) == 0)
	{
		if (data->parser->east_text_path != NULL)
			exit_error(MULTIPLE_TEXT, data);
		data->parser->east_text_path = ft_strdup(value);
	}
	else if (ft_strncmp(identifier, SOUTH_ID, ft_strlen(identifier)) == 0)
	{
		if (data->parser->south_text_path != NULL)
			exit_error(MULTIPLE_TEXT, data);
		data->parser->south_text_path = ft_strdup(value);
	}
	else if (ft_strncmp(identifier, WEST_ID, ft_strlen(identifier)) == 0)
	{
		if (data->parser->west_text_path != NULL)
			exit_error(MULTIPLE_TEXT, data);
		data->parser->west_text_path = ft_strdup(value);
	}
}

void	save_identifier(char *identifier, char *line, t_data *data)
{
	line += ft_strlen(identifier);
	check_texture_file(line, data);
	data->parser->line_trimmed = ft_strtrim(line, " \n");
	if (ft_strncmp(identifier, NORTH_ID, ft_strlen(identifier)) == 0)
		save_text_if_empty(data, identifier, data->parser->line_trimmed);
	else if (ft_strncmp(identifier, EAST_ID, ft_strlen(identifier)) == 0)
		save_text_if_empty(data, identifier, data->parser->line_trimmed);
	else if (ft_strncmp(identifier, SOUTH_ID, ft_strlen(identifier)) == 0)
		save_text_if_empty(data, identifier, data->parser->line_trimmed);
	else if (ft_strncmp(identifier, WEST_ID, ft_strlen(identifier)) == 0)
		save_text_if_empty(data, identifier, data->parser->line_trimmed);
	free(data->parser->line_trimmed);
	data->parser->line_trimmed = NULL;
}

void	check_texture_file(char *path, t_data *data)
{
	int		fd;

	path = ft_strtrim(path, " \n");
	fd = open(path, O_RDONLY);
	if (fd < 1)
	{
		free(path);
		exit_error(TEXTURE_ERR, data);
	}
	close(fd);
	free(path);
}

char	*remove_whitespace(char *src, t_data *data)
{
	int		i;
	int		j;
	int		count;
	char	*res;

	i = 0;
	count = 0;
	while (src[i])
	{
		if (src[i] == ' ')
			count++;
		i++;
	}
	res = malloc(sizeof(char) * (ft_strlen(src) - count) + 1);
	if (!res)
		exit_error(MALLOC_ERR, data);
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] != ' ')
			res[j++] = src[i];
		i++;
	}
	return (res[j] = '\0', res);
}
