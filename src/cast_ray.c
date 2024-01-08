/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:03:37 by jschott           #+#    #+#             */
/*   Updated: 2024/01/08 17:57:56 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

int	ray_collision(t_scene *scene, int pos[2])
{
	int	new_pos[2];

	new_pos[0] = pos[0];
	new_pos[1] = pos[1];
	new_pos[0] /= scene->map_square_scale;
	new_pos[1] /= scene->map_square_scale;
	printf("pos: %i, %i\nval: %c\n\n", new_pos[0], new_pos[1], scene->map[new_pos[1]][new_pos[0]]);
	if (scene->map[new_pos[1]][new_pos[0]] == '1')
		return (1);
	return (0);
}

int	find_next (int start[2], int square_scale, int dir) // REPLACE DIR WITH ANG?
{
	int	distance;

	if (dir == UP || dir == DOWN)
		distance = start[1];
	else
		distance = start[0];
	while (distance % square_scale)
	{
		if (dir == DOWN || dir == RIGHT)
			distance ++;
		if (dir == UP || dir == LEFT)
			distance --;
	}
	return (distance);
}

int	cast_ray(t_scene *scene, int angle)
{
	int	distance = 0;
	int	next_square[2];

	next_square[0] = scene->player_position[0];
	next_square[1] = scene->player_position[1];
	// while(!ray_collision(scene, next_square))
	// {
		printf("new_square: %i, %i\n", next_square[0], next_square[1]);
		next_square[0] = find_next(next_square, scene->map_square_scale, UP);
		next_square[1] = find_next(next_square, scene->map_square_scale, RIGHT);
		printf("new_square: %i, %i\n", next_square[0], next_square[1]);
		if (next_square[0] < next_square[1])
			next_square[1] = sin(degr_to_rad(angle)) * next_square[0] + scene->player_position[1];
		else if (next_square[0] > next_square[1])
			next_square[0] = cos(degr_to_rad(angle)) * next_square[1] + scene->player_position[1];
		printf("new_square: %i, %i\n\n", next_square[0], next_square[1]);
	// }
	// draw_line(scene->image, scene->player_position, next_square, COLOR_MAP_PLAYER);

	
	int scale = 0.25 * map_scale(scene->map_size);
	printf("scale: %i\n", scale);

	next_square[0] /= scene->map_square_scale;
	next_square[1] /= scene->map_square_scale;
	printf("scaled to: %i, %i\n\n\n", next_square[0], next_square[1]);
	next_square[0] *= scale;
	next_square[1] *= scale;

	
	my_mlx_pixel_put(scene->image, next_square[0], next_square[1], COLOR_MAP_PLAYER);
	printf("draw to: %i, %i\n\n\n", next_square[0], next_square[1]);
	distance = (int) sqrt (pow (next_square[0], 2) + pow(next_square[1], 2));
	return (distance);
}

// V.x = cos(A)
// V.y = sin(A)