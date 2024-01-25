/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:30:46 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 19:26:31 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	assign_textures(t_ray_result *rays[], t_xpm **textures, int end)
{
	int	i;

	printf("0: %s\n", textures[0]->filepath);
	printf("1: %s\n", textures[1]->filepath);
	printf("2: %s\n", textures[2]->filepath);
	printf("3: %s\n", textures[3]->filepath);

	i = -1;
	while (++i < end)
	{
		printf("x: %f y: %f degree: %f\n", rays[i]->x, rays[i]->y, rays[i]->degree);
		if (rays[i]->degree <= 90 || rays[i]->degree >= 270)
		{
			if (is_whole_number(rays[i]->y))
				rays[i]->xpm = textures[0];
			printf("assigned 0\n");
		}
		if (rays[i]->degree <= 180 && rays[i]->degree >= 0)
		{
			if (is_whole_number(rays[i]->x))
				rays[i]->xpm = textures[1];
			printf("assigned 1\n");
		}
		if (rays[i]->degree <= 270 && rays[i]->degree >= 90)
		{
			if (is_whole_number(rays[i]->y))
				rays[i]->xpm = textures[2];
			printf("assigned 2\n");
		}
		//else if (is_whole_number(rays[i]->x))
		else
		{
			rays[i]->xpm = textures[3];
			printf("assigned smthg\n");
		}
		//printf("1\n");
		//printf("assigned: %s\n", rays[i]->xpm->filepath);
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
	//printf("1: %s\n", env->wall_textures[0]->filepath);
	assign_textures(rays, env->wall_textures, FOV);
}
