/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:30 by jschott           #+#    #+#             */
/*   Updated: 2024/01/18 16:09:41 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

float	get_distance(int point_1[2], int point_2[2])
{
	float	distance;
	int		p_1[2];
	int		p_2[2];

	p_1[0] = point_1[0];
	p_1[1] = point_1[1];
	p_2[0] = point_2[0];
	p_2[1] = point_2[1];

	distance = sqrt (pow (p_2[0] - p_1[0], 2) + pow(p_2[1] - p_1[1], 2));
	return (distance);
}

float	degr_to_rad(float degrees)
{
	return (degrees * (M_PI / 180));
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

float	ft_absf(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}
