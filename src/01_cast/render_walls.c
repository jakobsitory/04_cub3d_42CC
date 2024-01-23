/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:30:46 by jschott           #+#    #+#             */
/*   Updated: 2024/01/23 17:27:04 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	assign_textures(t_ray_result *rays[], t_xpm **textures ,int end, int i)
{
	while (i < end)
	{
		if (rays[i]->degree <= 90 || rays[i]->degree >= 270)
		{
			if (is_whole_number(rays[i]->y))
				rays[i]->xpm = textures[0];
		}
		if (rays[i]->degree <= 180 && rays[i]->degree >= 0)
		{
			if (is_whole_number(rays[i]->x))
				rays[i]->xpm = textures[1];
		}
		if (rays[i]->degree <= 270 && rays[i]->degree >= 90)
		{
			if (is_whole_number(rays[i]->y))
				rays[i]->xpm = textures[2];
		}
		if (rays[i]->degree <= 360 && rays[i]->degree >= 180)
		{
			if (is_whole_number(rays[i]->x))
				rays[i]->xpm = textures[3];
		}
		i++;
	}
}

void	fix_fisheye(t_ray_result *rays[], int no_rays, int player_orientation)
{
	int		i;
	float	player_angle_rad;
	float	ray_angle_rad;
	float	diff_angle;

	player_angle_rad = degr_to_rad(player_orientation);
	i = -1;
	while (i++ < no_rays - 1) 
	{
		ray_angle_rad = degr_to_rad(rays[i]->degree);
		diff_angle = ray_angle_rad - player_angle_rad;
		while (diff_angle < -PI)
			diff_angle += 2 * PI;
		while (diff_angle > PI)
			diff_angle -= 2 * PI;
		rays[i]->distance = rays[i]->distance * cos(diff_angle);
	}
}

void	prepare_rays(t_scene *scene)
{
	int				i;
	t_ray_result	**rays;
	t_window		*window ;

	rays = scene->rays;
	window = scene->window;
	fix_fisheye(scene->rays, window->fov_degrees, scene->player_orientation);
	i = -1;
	while (i++ < WINDOW_W - 1)
	{
		rays[i]->line_height = (WINDOW_H) / rays[i]->distance;
		rays[i]->start_y = window->center_y - rays[i]->line_height / 2;
		rays[i]->end_y = window->center_y + rays[i]->line_height / 2;
	}
	assign_textures(rays, scene->textures, window->fov_degrees, 0);
}
