/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_rayresult.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:52:29 by jschott           #+#    #+#             */
/*   Updated: 2024/01/17 14:41:35 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

void	write_to_ray_results(t_ray_result *rays, int next_square[2], float distance, int i)
{
	// if (!rays || !next_square)
	// 	return ;
	// if (!rays)
		rays = (t_ray_result *) malloc (sizeof(t_ray_result));
	rays->x = next_square[0];
	rays->y = next_square[1];
	rays->distance = distance;
	/*
	printf("rays[].distance = %f;\nrays[].x = %f;\nrays[].y = %f\n", \
		rays->distance, \
		rays->x, \
		rays->y);
	*/
	i++;

	// printf("rays[%i].degree = %i;\n", i, i);
	// printf("rays[%i].distance = %f;\n", i, rays->distance);
	// printf("rays[%i].x = %f;\n", i, rays->x);
	// printf("rays[%i].y = %f;\n", i, rays->y);
}
