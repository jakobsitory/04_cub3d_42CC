/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:52:31 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/30 13:06:09 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_successful(t_data *data)
{
	if (data->env->floor_hex == -1)
		exit_error(COLOR_ERR, data);
	if (data->env->ceiling_hex == -1)
		exit_error(COLOR_ERR, data);
	if (!data->parser->north_text_path)
		exit_error(TEXTURE_ERR, data);
	if (!data->parser->east_text_path)
		exit_error(TEXTURE_ERR, data);
	if (!data->parser->south_text_path)
		exit_error(TEXTURE_ERR, data);
	if (!data->parser->west_text_path)
		exit_error(TEXTURE_ERR, data);
}

int	only_spaces(char *line)
{
	if (*line == '\n' || *line == '\0')
		return (0);
	while (*line)
	{
		if (*line != ' ' && *line != '\n' && *line != '\0') 
			return (0);
		line++;
	}
	return (1);
}

void	check_hex_range(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	while (i < 3)
	{
		if (data->parser->ceiling_colors[i] == -1)
			exit_error(COLOR_ERR, data);
		n = data->parser->ceiling_colors[i];
		if (n > 255 || n < 0)
			exit_error(COLOR_ERR, data);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (data->parser->floor_colors[i] == -1)
			exit_error(COLOR_ERR, data);
		n = data->parser->floor_colors[i];
		if (n > 255 || n < 0)
			exit_error(COLOR_ERR, data);
		i++;
	}
}

int	convert_to_hex(int rgb[3])
{
	int	hex;

	hex = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (hex);
}
