/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:57:45 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/11 17:13:49 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_error(char *msg, t_data *data)
{
	printf("Error\n");
	if (msg)
		printf("%s", msg);
	if (data)
		free_data(data);
	exit (1);
}

void	print_res(t_res *res)
{
	ft_printf("%s\n", res->north_text_path);
	ft_printf("%s\n", res->east_text_path);
	ft_printf("%s\n", res->south_text_path);
	ft_printf("%s\n", res->west_text_path);
	ft_printf("%i %i %i -> %x\n", res->floor_colors[0], res->floor_colors[1], res->floor_colors[2], res->floor_colors);
	ft_printf("%i %i %i -> %x\n", res->ceiling_colors[0], res->ceiling_colors[1], res->ceiling_colors[2], res->ceiling_colors);
}

void	print_map(t_map *map)
{
	print_string_array(map->map);
	ft_printf("Size [x, y]: [%i, %i]\n", map->map_size[0], map->map_size[1]);
	ft_printf("Player Pos [x, y]: [%i, %i]\n", map->player_position[0], map->player_position[1]);
	ft_printf("Player Orientation in degree: %i\n", map->player_orientation);
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

/* typedef struct map
{
	char		*map_string;
	int			map_size[2];
	int			map_square_scale;
	char		**map;
	char		**map_copy;
	int			player_position[2];
	int			player_orientation;
	int			*x_moves;
	int			*y_moves;
}	t_map;
 */

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

void	print_string_array(char **array)
{
	int	i;

	i = 0;
	while(array[i])
	{
		ft_printf("'%s'\n", array[i]);
		i++;
	}
	ft_printf("\n", array[i]);
}