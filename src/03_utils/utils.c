/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:57:45 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/26 13:04:13 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_error(char *msg, t_data *data)
{
	printf("Error\n");
	if (msg)
		printf("%s", msg);
	if (data)
		free_data(data);
	exit (1);
}
/* 
void	print_string_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		printf("'%s'\n", array[i]);
		i++;
	}
	printf("\n");
}

void	print_rays(t_ray_result **rays)
{
	int	i;

	i = -1;
	while (++i < WINDOW_W)
	{
		printf("\npos\t[%f, %f]\ndegr\t%f\ndist\t%f\n' \
				'height\t%i [%i to %i]\ntxtr\t %s", \
		rays[i]->x, \
		rays[i]->y, \
		rays[i]->degree, \
		rays[i]->distance, \
		rays[i]->line_height, \
		rays[i]->start_y, \
		rays[i]->end_y, \
		rays[i]->xpm->filepath);
	}
}

void	print_xpm(t_xpm *xpm)
{
	t_xpm_color	*tmp_color;
	int			i;

	printf("---GENERAL:---\n%i, %i, %i, %i\n", xpm->rows, xpm->columns, \
				xpm->colors_count, xpm->bytes_per_pixel);
	tmp_color = xpm->colors;
	printf("---COLORS---\n");
	while (tmp_color)
	{
		printf("%c->%s\n", tmp_color->c, tmp_color->hex_code);
		tmp_color = tmp_color->next;
	}
	printf("---IMAGE:---\n");
	i = -1;
	while (++i < xpm->rows)
		printf("%s\n", xpm->lines[i]);
	printf("---END---\n");
}

void	print_env(t_env *env)
{
	print_xpm(env->wall_textures[0]);
	print_xpm(env->wall_textures[1]);
	print_xpm(env->wall_textures[2]);
	print_xpm(env->wall_textures[3]);
	print_string_array(env->map);
	printf("map size: %i x %i\n", env->map_size[0], env->map_size[1]);
	printf("player position: %f x %f\n", \
			env->player_position[0], env->player_position[1]);
	printf("player orientation: %i\n", env->player_orientation);
	printf("floor hex: %x\n", env->floor_hex);
	printf("ceiling hex -> %x\n", env->ceiling_hex);
}
 */
