/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 08:36:45 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 08:40:31 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_frame(t_scene *scene)
{
	cast_all_rays(scene);
	prepare_rays(scene);
	background_fill(scene);
	draw_walls(scene);
	draw_map(scene);
	mlx_put_image_to_window(scene->window->mlx, scene->window->mlx_win, \
							scene->image->img, 0, 0);
}
