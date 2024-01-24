/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:25:00 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 17:17:42 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_window	*init_window(void)
{
	t_window	*window;

	window = (t_window *) malloc (sizeof(t_window));
	if (!window)
	{
		ft_putstr_fd("Error\ncouldn't create window.\n", 2);
		return (NULL);
	}
	window->mlx = mlx_init();
	window->mlx_win = mlx_new_window(window->mlx, \
											WINDOW_W, WINDOW_H, "cub3d");
	if (!window->mlx_win)
	{
		printf("couldn't create image\n");
		exit (1);
	}
	// sleep(1); // SLEEPER	

	window->img = mlx_new_image(window->mlx, WINDOW_W, WINDOW_H);
	// window->img_line_length = 100;
	// window->img_bits_per_pixel = 8;
	// window->img_endian = 0;
	window->img_addr = mlx_get_data_addr(window->img, \
											&window->img_bits_per_pixel, \
											&window->img_line_length, \
											&window->img_endian);
	printf("img_address: %s\n", window->img_addr);
	window->line_buffer = (t_line *) malloc (sizeof (t_line));
	if (!window->line_buffer)
		return (NULL); //TBD ERROR MGMT
	window->center_x = WINDOW_W / 2;
	window->center_y = WINDOW_H / 2;
	// window->px_per_ray = WINDOW_W / FOV;
	return (0);
}
