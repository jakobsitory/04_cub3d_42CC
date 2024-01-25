/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:24:06 by jschott           #+#    #+#             */
/*   Updated: 2024/01/25 12:10:10 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_frame(t_data *data)
{
	if (render_rays(data->rays, data->env))
		exit_error(RENDER_ERR, data);
	fix_fisheye(data->rays, WINDOW_W, data->env->player_orientation);
	render_walls(data->rays);
	assign_textures(data->rays, data->env);
}
