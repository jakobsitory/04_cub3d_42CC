/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:32:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/24 17:34:32 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_data(t_data *data)
{
	free_env(data);
	free_parser(data);
	if (data)
		free(data);
}

void	free_parser(t_data *data)
{
	if (data->parser->filepath)
		free(data->parser->filepath);
	if (data->parser->line)
		free(data->parser->line);
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
	if (data->parser)
		free(data->parser); 
}

void	free_xpm(t_xpm *xpm) {
	t_xpm_color *tmp;
	t_xpm_color *next;

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
	if (data->env->wall_textures[0])
		free_xpm(data->env->wall_textures[0]);
	if (data->env->wall_textures[1])
		free_xpm(data->env->wall_textures[1]);
	if (data->env->wall_textures[2])
		free_xpm(data->env->wall_textures[2]);
	if (data->env->wall_textures[3])
		free_xpm(data->env->wall_textures[3]);
	if (data->env->wall_textures)
		free(data->env->wall_textures);
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