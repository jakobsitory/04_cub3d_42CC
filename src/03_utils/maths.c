/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:30 by jschott           #+#    #+#             */
/*   Updated: 2024/01/25 18:46:23 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	get_distance(float point_1[2], float point_2[2])
{
	float	distance;
	float	p_1[2];
	float	p_2[2];

	p_1[0] = point_1[0];
	p_1[1] = point_1[1];
	p_2[0] = point_2[0];
	p_2[1] = point_2[1];
	distance = sqrtf (powf (p_2[0] - p_1[0], 2) + powf(p_2[1] - p_1[1], 2));
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

int	is_whole_number(float num)
{
	float	tolerance;

	tolerance = 0.000001f;
	if (fabs(num - round(num)) < tolerance)
		return (1);
	return (0);
}
