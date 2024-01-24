/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:43:27 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 16:36:23 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_ray_result	**init_rays(void)
{
	t_ray_result	**rays;
	int				i;

	rays = (t_ray_result **) malloc (WINDOW_W * sizeof(t_ray_result *));
	if (!rays)
		return (NULL); // MEMORY MGMT TBD
	i = -1;
	while (++i < WINDOW_W)
		rays[i] = (t_ray_result *) malloc (sizeof(t_ray_result)); // MEMORY MGMT TBD
	return (rays);
}
