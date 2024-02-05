/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:56:12 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/01 21:38:01 by lgrimmei         ###   ########.fr       */
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
		save_next_hex(line_trimmed_whitesp, data->parser->ceiling_colors, data);
	else if (ft_strncmp(identifier, FLOOR_ID, ft_strlen(identifier)) == 0)
		save_next_hex(line_trimmed_whitesp, data->parser->floor_colors, data);
	free(line_trimmed_whitesp);
}

void	check_color_saved(t_data *data, char *identifier)
{
	if (ft_strncmp(identifier, CEILING_ID, ft_strlen(identifier)) == 0)
	{
		if (data->parser->ceiling_colors[0] != -1)
			exit_error(MULTIPLE_COLOR, data);
	}
	else if (ft_strncmp(identifier, FLOOR_ID, ft_strlen(identifier)) == 0)
	{
		if (data->parser->floor_colors[0] != -1)
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
	int	nu;
	int	co;
	int	flag;

	nu = 0;
	co = 0;
	flag = 0;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			flag = 1;
		else 
		{
			if (flag)
				nu++;
			if (*str == ',')
				co++;
			flag = 0;
		}
		str++;
	}
	if (((nu == 3 && co == 2) && !flag) || ((nu == 2 && co == 2) && flag))
		return ;
	exit_error(COLOR_ERR, data);
}
