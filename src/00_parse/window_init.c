/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:25:00 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 09:22:24 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	scene->image->bits_per_pixel = 8;
	scene->image->img = mlx_new_image(scene->window->mlx, WINDOW_W, WINDOW_H);
	scene->image->addr = mlx_get_data_addr(scene->image->img, \
											&scene->image->bits_per_pixel, \
											&scene->image->line_length, \
											&scene->image->endian);
	scene->window->fov_degrees = WINDOW_W;
	scene->window->height_px = WINDOW_H;
	scene->window->width_px = WINDOW_W;
	scene->window->center_x = scene->window->width_px / 2;
	scene->window->center_y = scene->window->height_px / 2;
	scene->window->px_per_ray = scene->window->width_px / FOV;
	return (0);
}
