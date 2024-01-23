/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:56:12 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/23 16:21:15 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	save_color(char *identifier, char *line, t_data *data)
{
	char	*line_trimmed;
	char	*line_trimmed_whitesp;

	check_color_saved(data, identifier);
	line += ft_strlen(identifier);
	line_trimmed = ft_strtrim(line, "\n");
	while (*line == ' ')
		line++;
	valid_number_format(line_trimmed, data);
	line_trimmed_whitesp = remove_whitespace(line_trimmed, data);
	free(line_trimmed);
	valid_chars_color(line_trimmed_whitesp, data);
	if (ft_strncmp(identifier, CEILING_ID, ft_strlen(identifier)) == 0)
		save_next_hex(line_trimmed_whitesp, data->res->ceiling_colors, data);
	else if (ft_strncmp(identifier, FLOOR_ID, ft_strlen(identifier)) == 0)
		save_next_hex(line_trimmed_whitesp, data->res->floor_colors, data);
	free(line_trimmed_whitesp);
}

void	check_color_saved(t_data *data, char *identifier)
{
	if (ft_strncmp(identifier, CEILING_ID, ft_strlen(identifier)) == 0)
	{
		if (data->res->ceiling_colors[0] != -1)
			exit_error(MULTIPLE_COLOR, data);
	}
	else if (ft_strncmp(identifier, FLOOR_ID, ft_strlen(identifier)) == 0)
	{
		if (data->res->floor_colors[0] != -1)
			exit_error(MULTIPLE_COLOR, data);
	}
}

char	*save_next_hex(char *line, int *array, t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (j < 3)
	{
		while (line[i] != '\0' && line[i] != ',')
			i++;
		str = ft_substr(line, 0, i);
		array[j] = ft_atoi(str);
		free(str);
		line = line + i + 1;
		i = 0;
		j++;
	}
	line--;
	if (*line != '\0')
		exit_error(COLOR_ERR, data);
	return (NULL);
}

int	valid_chars_color(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ',' && (str[i] < '0' || str[i] > '9'))
			exit_error(COLOR_ERR, data);
		i++;
	}
	return (1);
}

void	valid_number_format(char *str, t_data *data)
{
	int	numbers;
	int	commas;
	int	i;

	numbers = 0;
	commas = 0;
	i = 0;
	while (i < (int)ft_strlen(str))
	{
		while (str[i] > 47 && str[i] < 57)
		{
			i++;
			if (!(str[i] > 47 && str[i] < 57))
				numbers++;
		}
		while (str[i] == ',')
		{
			i++;
			commas++;
		}
		i++;
	}
	if ((numbers == 3 && commas == 2))
		return ;
	exit_error(COLOR_ERR, data);
}
