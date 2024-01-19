/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:52:45 by jschott           #+#    #+#             */
/*   Updated: 2024/01/19 16:20:03 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

void	get_texture(t_ray_result *ray)
{
	if (ray->degree <= 90 || ray->degree >= 270)
	{
		if (is_whole_number(ray->y))
			ray->texture_path = ft_strdup(NORTH_TEXTURE);
	}
	else if (ray->degree <= 180 && ray->degree >= 0)
	{
		if (is_whole_number(ray->x))
			ray->texture_path = ft_strdup(EAST_TEXTURE);
	}
	else if (ray->degree <= 270 && ray->degree >= 90)
	{
		if (is_whole_number(ray->y))
			ray->texture_path = ft_strdup(SOUTH_TEXTURE);
	}
	else if (ray->degree <= 360 && ray->degree >= 180)
	{
		if (is_whole_number(ray->x))
			ray->texture_path = ft_strdup(WEST_TEXTURE);
	}
}

t_scene	*scene_init(void)
{
	t_scene	*scene;

	scene = (t_scene *) malloc (sizeof (t_scene));
	if (!scene)
		return (NULL);
	/* create map */
	scene->map = map_init();
	scene->map_size[0] = 8;
	scene->map_size[1] = 8;
	scene->map_scale = MINIMAP_SIZE * map_scale(scene->map_size);
	scene->map_square_scale = 100;
		
	scene->ray_resolution = (float)  FOV / (float) WINDOW_W;
	scene->rays = (t_ray_result **) malloc (WINDOW_W * sizeof(t_ray_result *));
	if (!scene->rays)
		return (NULL); // MEMORY MGMT TBD
	for (int i = 0; i < WINDOW_W; i++)
	{
		scene->rays[i] = (t_ray_result *) malloc (sizeof(t_ray_result)); // MEMORY MGMT TBD
		get_texture(scene->rays[i]);
	}
	/* Place Player on Map */
	scene->player_position[0] = (3.5 * scene->map_square_scale);
	scene->player_position[1] = (4.5 * scene->map_square_scale);
	scene->player_orientation = 360;
	return (scene);
}
