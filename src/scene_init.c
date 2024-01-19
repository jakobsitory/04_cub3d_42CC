/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:52:45 by jschott           #+#    #+#             */
/*   Updated: 2024/01/19 18:07:04 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"


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
	scene->map_ray = (t_line *) malloc (sizeof(t_line));
	if (!scene->map_ray)
		return (NULL); // MEMORY MGMT TBD

	scene->textures = malloc (sizeof(t_xpm *) * 4);
	if (!scene->textures)
		return (NULL); // MEMORY MGMT TBD
	scene->textures[0] = parse_xpm(NORTH_TEXTURE);
	scene->textures[1] = parse_xpm(EAST_TEXTURE);
	scene->textures[2] = parse_xpm(SOUTH_TEXTURE);
	scene->textures[3] = parse_xpm(WEST_TEXTURE);
	
	scene->ray_resolution = (float)  FOV / (float) WINDOW_W;
	scene->rays = (t_ray_result **) malloc (WINDOW_W * sizeof(t_ray_result *));
	if (!scene->rays)
		return (NULL); // MEMORY MGMT TBD
	for (int i = 0; i < WINDOW_W; i++)
		scene->rays[i] = (t_ray_result *) malloc (sizeof(t_ray_result)); // MEMORY MGMT TBD
	/* Place Player on Map */
	scene->player_position[0] = (3.5 * scene->map_square_scale);
	scene->player_position[1] = (4.5 * scene->map_square_scale);
	scene->player_orientation = 360;
	return (scene);
}
