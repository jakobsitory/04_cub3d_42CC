/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:44 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 16:30:34 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
