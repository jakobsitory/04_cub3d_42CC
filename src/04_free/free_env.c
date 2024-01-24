/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:10:36 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 16:16:16 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (i < 8)
		free (map[i++]);
	free(map);
}

void	free_env(t_env *env)
{
	int	i;

	free_map(env->map);
	i = -1;
	while (++i < 4)
		free (env->wall_textures[i]);
	free(env->wall_textures);
	free(env);
}
/* 
	rays = (t_ray_result **) malloc (WINDOW_W * sizeof(t_ray_result *));
	if (!rays)
		return (NULL); // MEMORY MGMT TBD
	i = -1;
	while (++i < WINDOW_W)
		rays[i] = (t_ray_result *) malloc (sizeof(t_ray_result)); // MEMORY MGMT TBD
	return (env);
} */