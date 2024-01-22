/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:32:59 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/22 10:46:28 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

void	free_data(t_data *data)
{
	free_res(data);
	free_map(data);
	if (data->filepath)
		free(data->filepath);
	if (data->line)
		free(data->line);
	if (data)
		free(data);
}

void	free_res(t_data *data)
{
	if (data->res->north_text_path)
		free(data->res->north_text_path);
	if (data->res->east_text_path)
		free(data->res->east_text_path);
	if (data->res->south_text_path)
		free(data->res->south_text_path);
	if (data->res->west_text_path)
		free(data->res->west_text_path);
	if (data->res)
		free(data->res);
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

void	free_map(t_data *data)
{
	if (data->map->map_string)
		free(data->map->map_string);
	if (data->map->x_moves)
		free(data->map->x_moves);
	if (data->map->y_moves)
		free(data->map->y_moves);
	if (data->map->map)
		free_str_arr(data->map->map);
	if (data->map->map_copy)
		free_str_arr(data->map->map_copy);
	if (data->map)
		free(data->map);
}
