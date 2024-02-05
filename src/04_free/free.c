/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:32:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/01 20:50:35 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_data(t_data *data)
{
	free_window(data->window);
	free_rays(data->rays);
	free_env(data);
	free_parser(data);
	if (data)
		free(data);
}

/* void	free_moves_array(int *array)
{
	if (array[0])
		free(array[0]);
	if (array[1])
		free(array[1]);
	if (array[2])
		free(array[2]);
	if (array[3])
		free(array[3]);
	if (array[4])
		free(array[4]);
	if (array[5])
		free(array[5]);
	if (array[6])
		free(array[6]);
	if (array[7])
		free(array[7]);
	if (array)
		free(array);
} */

void	free_parser(t_data *data)
{
	if (data->parser->filepath)
		free(data->parser->filepath);
	if (data->parser->line)
		free(data->parser->line);
	if (data->parser->line_trimmed)
		free(data->parser->line_trimmed);
	if (data->parser->north_text_path)
		free(data->parser->north_text_path);
	if (data->parser->east_text_path)
		free(data->parser->east_text_path);
	if (data->parser->south_text_path)
		free(data->parser->south_text_path);
	if (data->parser->west_text_path)
		free(data->parser->west_text_path);
	if (data->parser->map_string)
		free(data->parser->map_string);
	if (data->parser->map_copy)
		free_str_arr(data->parser->map_copy);
	if (data->parser->x_moves != NULL)
		free(data->parser->x_moves);
	if (data->parser->y_moves != NULL)
		free(data->parser->y_moves);
	if (data->parser)
		free(data->parser);
}

void	free_xpm(t_xpm *xpm)
{
	t_xpm_color	*tmp;
	t_xpm_color	*next;

	if (xpm->filepath)
		free(xpm->filepath);
	free_str_arr(xpm->lines);
	tmp = xpm->colors;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->hex_code);
		free(tmp);
		tmp = next;
	}
	if (xpm)
		free(xpm);
}

void	free_env(t_data *data)
{
	if (data->env->map)
		free_str_arr(data->env->map);
	if (data->env->wall_textures)
	{
		if (data->env->wall_textures[0])
			free_xpm(data->env->wall_textures[0]);
		if (data->env->wall_textures[1])
			free_xpm(data->env->wall_textures[1]);
		if (data->env->wall_textures[2])
			free_xpm(data->env->wall_textures[2]);
		if (data->env->wall_textures[3])
			free_xpm(data->env->wall_textures[3]);
	}
	if (data->env->wall_textures)
		free(data->env->wall_textures);
	if (data->env->background_hex)
		free(data->env->background_hex);
	if (data->env)
		free(data->env);
}

void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
