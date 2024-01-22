/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:23:29 by jschott           #+#    #+#             */
/*   Updated: 2024/01/19 18:04:05 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

void	print_xpm(t_xpm *xpm)
{
	printf("---GENERAL:---\n%i, %i, %i, %i\n", xpm->rows, xpm->columns, xpm->colors_count, xpm->bytes_per_pixel);
	t_xpm_color *tmp_color = xpm->colors;
	printf("---COLORS---\n");
	while (tmp_color)
	{
		printf("%c->%s\n", tmp_color->c, tmp_color->hex_code);
		tmp_color = tmp_color->next;
	}
	printf("---IMAGE:---\n");
	for (int i = 0; i < xpm->rows; i++)
		printf("%s\n", xpm->lines[i]);
	printf("---END---\n");
}

t_xpm	*init_xpm(char *filename)
{
	t_xpm	*xpm;
	xpm = malloc(sizeof(t_xpm));
	if (!xpm)
		return (NULL);
	xpm->colors = (t_xpm_color *) malloc(sizeof(t_xpm_color));
	if (!xpm->colors)
		return (NULL);
	xpm->colors = NULL;
	xpm->fd = open(filename, O_RDONLY);
	if (xpm->fd < 0)
	{
		ft_printf("could not open xpm: %s\n", filename);
		exit (0);
	}
	return (xpm);
}