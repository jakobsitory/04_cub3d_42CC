/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:24:06 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 13:02:29 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Renders a single frame in the game, including raycasting results, wall rendering, and texture assignment.
 * 
 * @param data Pointer to the t_data structure containing all necessary data for rendering the frame.
 */
void	render_frame(t_data *data)
{
	if (render_rays(data->rays, data->env))
		exit_error(RENDER_ERR, data);
	fix_fisheye(data->rays, WINDOW_W, data->env->player_orientation);
	render_walls(data->rays);
	assign_textures(data->rays, data->env);
}
