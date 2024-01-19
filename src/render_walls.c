/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:30:46 by jschott           #+#    #+#             */
/*   Updated: 2024/01/19 16:32:25 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"


void	assign_textures(t_ray_result *rays[], int no_rays, int i)
{
	while (i < no_rays)
	{
		if (rays[i]->degree <= 90 || rays[i]->degree >= 270)
		{
			if (is_whole_number(rays[i]->y))
				rays[i]->texture_path = ft_strdup(NORTH_TEXTURE);
		}
		if (rays[i]->degree <= 180 && rays[i]->degree >= 0)
		{
			if (is_whole_number(rays[i]->x))
				rays[i]->texture_path = ft_strdup(EAST_TEXTURE);
		}
		if (rays[i]->degree <= 270 && rays[i]->degree >= 90)
		{
			if (is_whole_number(rays[i]->y))
				rays[i]->texture_path = ft_strdup(SOUTH_TEXTURE);
		}
		if (rays[i]->degree <= 360 && rays[i]->degree >= 180)
		{
			if (is_whole_number(rays[i]->x))
				rays[i]->texture_path = ft_strdup(WEST_TEXTURE);
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

	player_angle_rad = degr_to_rad((float) player_orientation);
	i = -1;
	printf("checking:\n");
	while (i++ < no_rays) 
	{
		printf("%f ", rays[i]->degree);
		ray_angle_rad = degr_to_rad(rays[i]->degree);
		diff_angle = ray_angle_rad - player_angle_rad;
		while (diff_angle < -M_PI)
			diff_angle += 2 * M_PI;
		while (diff_angle > M_PI)
			diff_angle -= 2 * M_PI;
		rays[i]->distance = rays[i]->distance * cos(diff_angle);
	}
}

void	prepare_rays(t_scene *scene)
{
	int				i;
	t_ray_result	**rays = scene->rays;
	t_window		*window = scene->window;

	//fix_fisheye(scene->rays, window->fov_degrees, scene->player_orientation);
	i = -1;
	while (i++ < window->fov_degrees - 1)
	{
		rays[i]->line_height = (80 * 900) / rays[i]->distance;
		rays[i]->start_y = window->center_y - rays[i]->line_height / 2;
		rays[i]->end_y = window->center_y + rays[i]->line_height / 2;
	}	
	i = -1;
	assign_textures(rays, window->fov_degrees, 0);
	while (i++ < window->fov_degrees - 1)
		rays[i]->xpm = parse_xpm(rays[i]->texture_path);
}