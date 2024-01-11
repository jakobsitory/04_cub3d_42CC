/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:25:00 by jschott           #+#    #+#             */
/*   Updated: 2024/01/11 17:12:26 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

int	win_init(t_scene *scene)
{
	scene->window = (t_window *) malloc (sizeof(t_window));
	if (!scene->window)
	{
		ft_putstr_fd("Error\ncouldn't create window.\n", 2);
		return (1);
	}
	scene->window->mlx = mlx_init();
	scene->window->mlx_win = mlx_new_window(scene->window->mlx, \
											WINDOW_W, WINDOW_H, "cub3d");
	scene->image = (void *) malloc (sizeof(t_image));
	if (!scene->image)
	{
		ft_putstr_fd("Error\ncouldn't create image.\n", 2);
		mlx_destroy_window(scene->window->mlx, scene->window->mlx_win);
		mlx_destroy_display(scene->window->mlx);
		return (1);
	}
	scene->image->line_length = 100;
	scene->image->img = mlx_new_image(scene->window->mlx, WINDOW_W, WINDOW_H);
	scene->image->addr = mlx_get_data_addr(scene->image->img, \
											&scene->image->bits_per_pixel, \
											&scene->image->line_length, \
											&scene->image->endian);
	return (0);
}
