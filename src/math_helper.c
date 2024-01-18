/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:18:36 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/17 11:33:00 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_whole_number(float num)
{
	if (num == (int)num)
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
