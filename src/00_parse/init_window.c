/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:25:00 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 12:51:54 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Initializes the window component of the t_data structure for the cub3D project. Allocates memory for the t_window structure,
 * initializes the MiniLibX window, and creates an image to be used for rendering. Sets initial values for image properties and
 * allocates memory for a line buffer used in rendering.
 * 
 * @param data Pointer to the t_data structure, used for error handling.
 * @return Pointer to the initialized t_window structure.
 */
t_window	*init_window(t_data *data)
{
	t_window	*window;

	window = (t_window *) malloc (sizeof(t_window));
	if (!window)
		exit_error(MALLOC_ERR, data);
	window->mlx = mlx_init();
	if (!window->mlx)
		exit_error(WINDOW_ERR, data);
	window->mlx_win = mlx_new_window(window->mlx, \
											WINDOW_W, WINDOW_H, "cub3d");
	if (!window->mlx_win)
		exit_error(WINDOW_ERR, data);
	window->img = mlx_new_image(window->mlx, WINDOW_W, WINDOW_H);
	if (!window->img)
		exit_error(IMAGE_ERR, data);
	window->img_line_length = 100;
	window->img_addr = mlx_get_data_addr(window->img, \
											&window->img_bits_per_pixel, \
											&window->img_line_length, \
											&window->img_endian);
	window->line_buffer = (t_line *) malloc (sizeof (t_line));
	if (!window->line_buffer)
		exit_error(MALLOC_ERR, data);
	return (window);
}
