/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:56:12 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/08/08 12:55:06 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Parses and saves the color values from a configuration line for either the ceiling or the floor in the cub3D game. The function
 * processes the line by trimming newline characters, removing extra whitespaces, and validating the format and characters of the
 * color values. The color values are expected to be in RGB format, separated by commas. If the color for the specified identifier
 * (ceiling or floor) has already been set, or if the format is invalid, the program exits with an error.
 * 
 * @param identifier A string indicating whether the color is for the ceiling (CEILING_ID) or the floor (FLOOR_ID).
 * @param line The configuration line containing the color values.
 * @param data Pointer to the t_data structure containing game data and settings.
 */
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

/**
 * Checks if the color for either the ceiling or the floor has already been saved in the parser component of the t_data structure.
 * If the color for the specified identifier (ceiling or floor) has already been set, the program exits with an error to prevent
 * multiple definitions of the same color.
 * 
 * @param data Pointer to the t_data structure containing game data and settings.
 * @param identifier A string indicating whether the color is for the ceiling (CEILING_ID) or the floor (FLOOR_ID).
 */
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

/**
 * Parses a line of text to extract and save RGB color values into an array. The function iterates over the line, extracting numbers
 * separated by commas, and converts them to integers representing RGB values. If the line contains more characters after extracting
 * three values, or if the format is incorrect, the program exits with an error.
 * 
 * @param line The line of text containing RGB values separated by commas.
 * @param array An array where the parsed RGB values are stored.
 * @param data Pointer to the t_data structure for error handling.
 * @return Always returns NULL. Used to indicate the end of processing.
 */
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

/**
 * Validates that a string contains only numeric characters or commas. This function is used to ensure that a line specifying color
 * values contains valid characters before parsing. If invalid characters are found, the program exits with an error.
 * 
 * @param str The string to be validated.
 * @param data Pointer to the t_data structure for error handling.
 * @return Returns 1 if the string contains only valid characters, indicating it is safe to proceed with parsing.
 */
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

/**
 * Validates the format of a string containing numeric RGB values separated by commas. This function checks that there are exactly
 * three numbers separated by two commas, and that the string ends after the third number. If the format is incorrect, the program
 * exits with an error.
 * 
 * @param str The string containing RGB values to be validated.
 * @param data Pointer to the t_data structure for error handling.
 */
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
