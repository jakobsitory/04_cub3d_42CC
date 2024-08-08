/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:43:27 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 12:51:42 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Allocates and initializes an array of t_ray_result pointers, one for each vertical slice of the game window, to store the results
 * of raycasting operations. Each t_ray_result structure contains information about a ray's intersection with walls, such as distance
 * and the wall's texture.
 * 
 * @param data Pointer to the t_data structure, used for error handling.
 * @return Pointer to the array of t_ray_result pointers.
 */
t_ray_result	**init_rays(t_data *data)
{
	t_ray_result	**rays;
	int				i;

	rays = (t_ray_result **) malloc (WINDOW_W * sizeof(t_ray_result *));
	if (!rays)
		exit_error(MALLOC_ERR, data);
	i = -1;
	while (++i < WINDOW_W)
	{
		rays[i] = (t_ray_result *) malloc (sizeof(t_ray_result));
		if (!rays[i])
			exit_error(MALLOC_ERR, data);
	}
	return (rays);
}
