/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:30:46 by jschott           #+#    #+#             */
/*   Updated: 2024/01/25 15:28:58 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	assign_textures(t_ray_result *rays[], t_env *env)
{
	int	i;

	i = -1;
	while (++i < WINDOW_W)
	{
		if (((int)rays[i]->degree <= 90 || (int)rays[i]->degree >= 270) && (is_whole_number(rays[i]->y)))
		{
				rays[i]->xpm = env->wall_textures[0];
		}
		if (((int)rays[i]->degree <= 180 &&(int)rays[i]->degree >= 0) && (is_whole_number(rays[i]->x)))
		{
				rays[i]->xpm =  env->wall_textures[1];
		}
		if (((int)rays[i]->degree <= 270 &&(int)rays[i]->degree >= 90) && (is_whole_number(rays[i]->y)))
		{
				rays[i]->xpm =  env->wall_textures[2];
		}
		else if ((int)rays[i]->degree < 360 &&(int)rays[i]->degree > 180 && is_whole_number(rays[i]->x))
			rays[i]->xpm =  env->wall_textures[3];
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

int	render_walls(t_ray_result **rays)
{
	int				i;

	i = -1;
	while (++i < WINDOW_W)
	{
		rays[i]->line_height = (WINDOW_H) / rays[i]->distance;
		rays[i]->start_y = (WINDOW_H / 2) - rays[i]->line_height / 2;
		rays[i]->end_y =  (WINDOW_H / 2) + rays[i]->line_height / 2;
 		// if (rays[i]->start_y < 0)
		// {
			// rays[i]->start_y = 0;
			// rays[i]->end_y = WINDOW_H;

		// }
		//printf("start y %i end y %i\n", rays[i]->start_y, rays[i]->end_y);
	}
	return (0);
}
