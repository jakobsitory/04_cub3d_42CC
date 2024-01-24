/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:27:29 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 16:41:23 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3D.h"

t_env	*init_env(char **map)
{
	t_env	*env;

	env = (t_env *) malloc (sizeof (t_env));
	if (!map || !env)
		return (NULL);
	env->map = map;
	env->map_size[0] =  7; //FUNCTION THAT RETURNS COLS
	env->map_size[1] =  7; //FUNCTION THAT RETURNS LINES
	env->map_scale = MINIMAP_SIZE * map_scale(env->map_size);
	env->floor_hex = COLOR_FLOOR;
	env->ceiling_hex = COLOR_CEILING;
	env->wall_textures = malloc (sizeof(t_xpm *) * 4);
	if (!env->wall_textures)
		return (NULL); // MEMORY MGMT TBD
	env->wall_textures[0] = parse_xpm(NORTH_TEXTURE);
	env->wall_textures[1] = parse_xpm(EAST_TEXTURE);
	env->wall_textures[2] = parse_xpm(SOUTH_TEXTURE);
	env->wall_textures[3] = parse_xpm(WEST_TEXTURE);

	env->degr_per_ray = (float) FOV / (float) WINDOW_W;

	/* Place Player on Map */
	env->player_position[1] = 3.5;
	env->player_position[0] = 4.5;
	env->player_orientation = 0;
	return (env);
}
