/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:27:29 by jschott           #+#    #+#             */
/*   Updated: 2024/01/23 17:27:48 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

t_scene	*scene_init(t_data *data)
{
	t_scene	*scene;

	scene = (t_scene *) malloc (sizeof (t_scene));
	if (!scene || !data)
		return (NULL);
	scene->map = data->map->map;
	scene->map_size[0] = data->map->map_size[0];
	scene->map_size[1] = data->map->map_size[1];
	scene->map_scale = MINIMAP_SIZE * map_scale(scene->map_size);
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
	scene->ray_resolution = (float) FOV / (float) WINDOW_W;
	scene->rays = (t_ray_result **) malloc (WINDOW_W * sizeof(t_ray_result *));
	if (!scene->rays)
		return (NULL); // MEMORY MGMT TBD
	for (int i = 0; i < WINDOW_W; i++)
		scene->rays[i] = (t_ray_result *) malloc (sizeof(t_ray_result)); // MEMORY MGMT TBD
	/* Place Player on Map */
	scene->player_position[1] = data->map->player_position[1];
	scene->player_position[0] = data->map->player_position[0];
	scene->player_speed = .1f;
	scene->player_orientation = data->map->player_orientation;
	return (scene);
}
