/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors_help.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:56:12 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/08 20:05:59 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

int		valid_chars_color(char *str, t_data *data)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] != ',' && (str[i] < 48 && str[i] > 57))
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
	while (str[i])
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
	free(line);
	exit_error(COLOR_ERR, data);
}

void	check_hex_range(t_data *data)
{
	int	i;
	int	n;

	i = 0;
	while (i < 3)
	{
		n = data->res->ceiling_colors[i];
		if (n > 255 || n < 0)
			exit_error(COLOR_ERR, data);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		n = data->res->floor_colors[i];
		if (n > 255 || n < 0)
			exit_error(COLOR_ERR, data);
		i++;
	}
}

