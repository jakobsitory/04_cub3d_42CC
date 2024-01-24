/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:30:46 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 16:42:44 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	assign_textures(t_ray_result *rays[], t_xpm **textures, int end)
{
	int	i;

	i = -1;
	while (++i < end)
	{
		if (rays[i]->degree <= 90 || rays[i]->degree >= 270)
		{
			if (is_whole_number(rays[i]->y))
				rays[i]->xpm = textures[0];
		}
		else if (rays[i]->degree <= 180 && rays[i]->degree >= 0)
		{
			if (is_whole_number(rays[i]->x))
				rays[i]->xpm = textures[1];
		}
		else if (rays[i]->degree <= 270 && rays[i]->degree >= 90)
		{
			if (is_whole_number(rays[i]->y))
				rays[i]->xpm = textures[2];
		}
		else if (is_whole_number(rays[i]->x))
			rays[i]->xpm = textures[3];
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

void	render_walls(t_ray_result **rays, t_env *env)
{
	int				i;

	fix_fisheye(rays, FOV, env->player_orientation);
	i = -1;
	// rays[i]->start_y = WINDOW_H / 2;
	// rays[i]->end_y = WINDOW_H / 2;
	while (i++ < WINDOW_W - 1)
	{
		rays[i]->line_height = (WINDOW_H) / rays[i]->distance;
		rays[i]->start_y -= rays[i]->line_height / 2;
		rays[i]->end_y += rays[i]->line_height / 2;
	}
	assign_textures(rays, env->wall_textures, FOV);
}
