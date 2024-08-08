/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:44 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 12:58:38 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Deallocates memory allocated for an array of `t_ray_result` pointers, representing the results of raycasting operations for each
 * vertical slice of the game window. Iterates through the array, freeing each `t_ray_result` structure, and then frees the array itself.
 * 
 * @param rays A pointer to the first element in an array of `t_ray_result` pointers to be freed.
 */
void	free_rays(t_ray_result **rays)
{
	int	i;

	if (!rays)
		return ;
	i = -1;
	while (++i < WINDOW_W)
		free(rays[i]);
	free(rays);
}
