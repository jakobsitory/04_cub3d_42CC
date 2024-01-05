/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:30 by jschott           #+#    #+#             */
/*   Updated: 2024/01/05 16:46:07 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

float	degr_to_rad(int degrees)
{
	return (degrees * (M_PI / 180));
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
