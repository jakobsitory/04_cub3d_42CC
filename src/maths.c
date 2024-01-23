/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:22:30 by jschott           #+#    #+#             */
/*   Updated: 2024/01/23 14:24:02 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"
#include <math.h>

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
int is_whole_number(float num)
{
	float	tolerance;

	tolerance = 0.000001f;
	if (fabs(num - round(num)) < tolerance)
		return (1);
	return (0);
}

char	*get_hex_from_char(char c, t_xpm *xpm)
{
	t_xpm_color *tmp;

	tmp = xpm->colors;
	while (tmp)
	{
		if (tmp->c == c)
			return (tmp->hex_code);
		tmp = tmp->next;
	}
	return (NULL);
}

int hex_digit_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int hex_to_int(char *hex)
{
	int	r;
	int	g;
	int	b;
	int	i;

	r = 0;
	g = 0;
	b = 0;
	i = 1;
	if (ft_strlen(hex) < 7 || hex[0] != '#')
		return (-1);
	while (i < 7) {
		int value = hex_digit_to_int(hex[i]);
		if (value == -1)
			return (-1);
		if (i < 3)
			r = r * 16 + value;
		else if (i < 5)
			g = g * 16 + value;
		else
			b = b * 16 + value;
		i++;
	}
	return ((r & 0xFF) << 16) + ((g & 0xFF) << 8) + (b & 0xFF);
}
