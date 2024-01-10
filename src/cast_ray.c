/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:03:37 by jschott           #+#    #+#             */
/*   Updated: 2024/01/10 12:45:20 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define COLOR_GREEN 0x0020fc03
#define COLOR_BLUE 0x00003cff

int	ray_collision(t_scene *scene, int pos[2], int dir_x, int dir_y)
{
	int	new_pos[2];

	new_pos[0] = pos[0];
	new_pos[1] = pos[1];
	// printf("pos: %i, %i\n", new_pos[0], new_pos[1]);
	new_pos[0] /= scene->map_square_scale;
	new_pos[1] /= scene->map_square_scale;
	// printf("map square: %i, %i\nval: %c\n\n", new_pos[0], new_pos[1], scene->map[new_pos[1]][new_pos[0]]);
	if (scene->map[new_pos[1]][new_pos[0]] == '1')
		return (1);
	new_pos[0] = dir_x + dir_y;
	return (0);
}

int	find_next (int start[2], int square_scale, int dir) // REPLACE DIR WITH ANG?
{
	int	distance;

	if (dir == UP || dir == DOWN)
		distance = start[1];
	else
		distance = start[0];
	while (1)
	{
// printf("%i ", distance);
		if (dir == DOWN || dir == RIGHT)
			distance ++;
		if (dir == UP || dir == LEFT)
			distance --;
		if (0 == distance % square_scale)
			break ;
	}
// printf("%i\n", distance);
	return (distance);
}

int	cast_ray(t_scene *scene, int angle)
{
	int	distance = 0;
	int *next_square;
	int	square_0[2];
	int	square_1[2];
	int	dir_x;
	int	dir_y;

	if (angle < 180)
		dir_x = RIGHT;
	if (angle >= 180)
		dir_x = LEFT;
	if (angle < 90 || angle > 270)
		dir_y = UP;
	if (angle >= 90 && angle <= 270)
		dir_y = DOWN;
	// printf("directions: %i, %i\n", dir_x, dir_y);
	next_square = scene->player_position;
	// printf("initial square: %i, %i\n", next_square[0], next_square[1]);
	while(1)
	{
		square_0[1] = next_square[1];
		square_1[0] = next_square[0];
		square_0[1] = find_next(square_0, scene->map_square_scale, dir_y);
		square_0[0] = ft_abs(square_0[1] - scene->player_position[1]) \
						* tan(degr_to_rad(angle)) + scene->player_position[0];
		square_1[0] = find_next(square_1, scene->map_square_scale, dir_x);
		square_1[1] = ft_abs(square_1[0] - scene->player_position[0]) \
						* tanf(degr_to_rad(angle)) + scene->player_position[0];
		printf("next_square A:\t%i, %i\nnext_square B:\t%i, %i\n",\
		square_0[0],\
		square_0[1],\
		square_1[0],\
		square_1[1]);
/* 		printf("distance A:\t%f\ndistance B:\t%f\n", \
					get_distance(scene->player_position, square_0),\
					get_distance(scene->player_position, square_1)); */
		if(get_distance(scene->player_position, square_0) \
			< get_distance(scene->player_position, square_1))
			next_square = square_0;
		else
			next_square = square_1;
		if (ray_collision(scene, next_square, dir_x, dir_y))
			break ;
		// printf("new square: %i, %i\n", next_square[0], next_square[1]);
	}
	distance = get_distance(scene->player_position, next_square);
	int scale = map_scale(scene->map_size);
	next_square[0] *= scale;
	next_square[1] *= scale;
	next_square[0] /= scene->map_square_scale;
	next_square[1] /= scene->map_square_scale;
	// printf("scaled to: %i, %i\n\n\n", next_square[0], next_square[1]);
	int	player_tmp[2];
	player_tmp[1] = scale * scene->player_position[1] / scene->map_square_scale;
	player_tmp[0] = scale * scene->player_position[0] / scene->map_square_scale;
	// printf("draw to: %i, %i\n\n\n", next_square[0], next_square[1]);
	draw_line(scene->image, player_tmp, next_square, COLOR_MAP_PLAYER);
	return (distance);
}
