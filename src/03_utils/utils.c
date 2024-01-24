/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:57:45 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/24 13:12:29 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_error(char *msg, t_data *data)
{
	printf("Error\n");
	if (msg || data)
		printf("%s", msg);
	/* if (data)
		free_data(data); */
	exit (1);
}

/* void	print_res(t_res *res)
{
	ft_printf("%s\n", res->north_text_path);
	ft_printf("%s\n", res->east_text_path);
	ft_printf("%s\n", res->south_text_path);
	ft_printf("%s\n", res->west_text_path);
	ft_printf("%i %i %i -> %x\n", res->floor_colors[0], res->floor_colors[1] \
	, res->floor_colors[2], res->floor_colors);
	ft_printf("%i %i %i -> %x\n", res->ceiling_colors[0], res->ceiling_colors[1] \
	, res->ceiling_colors[2], res->ceiling_colors);
} */
/* 
void	print_map(t_map *map)
{
	print_string_array(map->map);
	ft_printf("Size [x, y]: [%i, %i]\n", map->map_size[0], map->map_size[1]);
	ft_printf("Player Pos [x, y]: [%i, %i]\n", map->player_position[0], \
	map->player_position[1]);
	ft_printf("Player Orientation in degree: %i\n", map->player_orientation);
} */

void	print_string_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("'%s'\n", array[i]);
		i++;
	}
	ft_printf("\n", array[i]);
}
