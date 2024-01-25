/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:43:27 by jschott           #+#    #+#             */
/*   Updated: 2024/01/25 17:53:11 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
