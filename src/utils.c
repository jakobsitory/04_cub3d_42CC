/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:57:45 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/08 19:47:28 by lgrimmei         ###   ########.fr       */
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
	ft_printf("%i %i %i\n", res->floor_colors[0], res->floor_colors[1], res->floor_colors[2]);
	ft_printf("%i %i %i\n", res->ceiling_colors[0], res->ceiling_colors[1], res->ceiling_colors[2]);
}

void	free_data(t_data *data)
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
	if (data->filepath)
		free(data->filepath);
	if (data)
		free(data);
}