/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:06:18 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/10 19:39:51 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int* create_possible_moves_x(t_data *data)
{
	int	*x_moves;
	
	x_moves = malloc(8 * sizeof(int));
	if (!x_moves) 
		exit_error(MALLOC_ERR, data);
	x_moves[0] = -1;
	x_moves[1] = 0;
	x_moves[2] = 1;
	x_moves[3] = -1;
	x_moves[4] = 1;
	x_moves[5] = -1;
	x_moves[6] = 0;
	x_moves[7] = 1;
	return (x_moves);
}

int* create_possible_moves_y(t_data *data)
{
	int	*y_moves;

	y_moves = malloc(8 * sizeof(int));
	if (!y_moves) 
		exit_error(MALLOC_ERR, data);
	y_moves[0] = 1;
	y_moves[1] = 1;
	y_moves[2] = 1;
	y_moves[3] = 0;
	y_moves[4] = 0;
	y_moves[5] = -1;
	y_moves[6] = -1;
	y_moves[7] = -1;
	return (y_moves);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit_error(MALLOC_ERR, data);
	data->res = malloc(sizeof(t_res));
	if (!data->res)
		exit_error(MALLOC_ERR, data);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		exit_error(MALLOC_ERR, data);
	data->res->north_text_path = NULL;
	data->res->east_text_path = NULL;
	data->res->south_text_path = NULL;
	data->res->west_text_path = NULL;
	data->line = NULL;
	data->map->map_string = ft_strdup("");
	data->map->map = NULL;
	data->map->map_copy = NULL;
	data->map->x_moves = create_possible_moves_x(data);
	data->map->y_moves = create_possible_moves_y(data);
	return (data);
}
