/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:36:45 by jschott           #+#    #+#             */
/*   Updated: 2024/01/30 13:11:31 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_frame(t_data *data)
{
	draw_background(data->window, data->env);
	draw_walls(data);
	if (SHADER)
		draw_map(data);
	mlx_put_image_to_window(data->window->mlx, data->window->mlx_win, \
							data->window->img, 0, 0);
}
