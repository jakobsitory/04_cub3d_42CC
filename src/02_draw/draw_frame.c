/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:36:45 by jschott           #+#    #+#             */
/*   Updated: 2024/01/25 11:04:24 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_frame(t_data *data)
{
	draw_background(data->window, data->env);
	draw_walls(data);
	// print_xpm(data->env->wall_textures[0]);
	draw_map(data);
	mlx_put_image_to_window(data->window->mlx, data->window->mlx_win, \
							data->window->img, 0, 0);
}
