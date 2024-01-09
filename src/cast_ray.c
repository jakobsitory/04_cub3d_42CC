/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:03:37 by jschott           #+#    #+#             */
/*   Updated: 2024/01/09 18:00:25 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define COLOR_GREEN 0x0020fc03
#define COLOR_BLUE 0x00003cff

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
	// if (distance % square_scale)
	// 	++distance;
printf("distance: ");
	while (distance % square_scale)
	{
printf("%i ", distance);
		if (dir == DOWN || dir == RIGHT)
			distance ++;
		if (dir == UP || dir == LEFT)
			distance --;
	}
printf("%i\n", distance);
	return (distance);
}

int	cast_ray(t_scene *scene, int angle)
{
	int	distance = 0;
	int *next_square;
	int	next_square_0[2];
	int	next_square_1[2];
	int	dir_x;
	int	dir_y;
	// int	direction;

	// angle = 45;

	if (angle < 180)
		dir_x = RIGHT;
	if (angle >= 180)
		dir_x = LEFT;
	if (angle < 90 || angle > 270)
		dir_y = UP;
	if (angle >= 90 && angle <= 270)
		dir_y = DOWN;

	// printf("directions: %i, %i\n", dir_x, dir_y);

	next_square = next_square_0;
	next_square[0] = scene->player_position[0];
	next_square[1] = scene->player_position[1];
	printf("initial square: %i, %i\n", next_square[0], next_square[1]);

	// while(!ray_collision(scene, next_square))
	// {
		next_square_0[0] = next_square[0];
		next_square_0[1] = next_square[1];
		next_square_1[0] = next_square[0];
		next_square_1[1] = next_square[1];

		next_square_0[1] = find_next(next_square_0, scene->map_square_scale, dir_y);
		next_square_0[0] = ft_abs(next_square_0[1] - scene->player_position[1]) * tan(degr_to_rad(angle)) + scene->player_position[0];

		next_square_1[0] = find_next(next_square_1, scene->map_square_scale, dir_x);
		next_square_1[1] = ft_abs(next_square_1[0] - scene->player_position[0]) * tanf(degr_to_rad(angle)) + scene->player_position[0];


		printf("next_square A:\t%i, %i\nnext_square B:\t%i, %i\n",\
		next_square_0[0],\
		next_square_0[1],\
		next_square_1[0],\
		next_square_1[1]);
		printf("distance A:\t%f\ndistance B:\t%f\n", \
					get_distance(scene->player_position, next_square_0),\
					get_distance(scene->player_position, next_square_1));

		if(get_distance(scene->player_position, next_square_0) < get_distance(scene->player_position, next_square_1))
			next_square = next_square_0;
		else
			next_square = next_square_1;
		printf("new square: %i, %i\n", next_square[0], next_square[1]);

	
	int scale = map_scale(scene->map_size);
	// printf("scale: %i\n", scale);

	next_square[0] *= scale;
	next_square[1] *= scale;
	next_square[0] /= scene->map_square_scale;
	next_square[1] /= scene->map_square_scale;


	// next_square_0[0] *= scale;
	// next_square_0[1] *= scale;
	// next_square_0[0] /= scene->map_square_scale;
	// next_square_0[1] /= scene->map_square_scale;

	// next_square_1[0] *= scale;
	// next_square_1[1] *= scale;
	// next_square_1[0] /= scene->map_square_scale;
	// next_square_1[1] /= scene->map_square_scale;
	// printf("scaled to: %i, %i\n\n\n", next_square[0], next_square[1]);

	int	player_tmp[2];
	player_tmp[1] = scale * scene->player_position[1] / scene->map_square_scale;
	player_tmp[0] = scale * scene->player_position[0] / scene->map_square_scale;
	
	// printf("draw to: %i, %i\n\n\n", next_square[0], next_square[1]);
	// my_mlx_pixel_put(scene->image, next_square[0], next_square[1], COLOR_MAP_PLAYER);
	draw_line(scene->image, player_tmp, next_square, COLOR_MAP_PLAYER);
	// draw_line(scene->image, player_tmp, next_square_0, COLOR_GREEN);
	// draw_line(scene->image, player_tmp, next_square_1, COLOR_BLUE);

	// distance = (int) sqrt (pow (next_square[0], 2) + pow(next_square[1], 2));
	return (distance);
}

/* int	cast_ray(t_scene *scene, int angle)
{
	int	distance = 0;
	int	next_square[2];
	int	next_square_2[2];
	int	dir_x;
	int	dir_y;
	int	direction;

	if (angle < 180)
		dir_x = RIGHT;
	if (angle >= 180)
		dir_x = LEFT;
	if (angle < 90 || angle > 270)
		dir_y = UP;
	if (angle >= 90 && angle <= 270)
		dir_y = DOWN;

	if (angle <= 45 || angle > 315)
		direction = UP;
	if (angle <= 135 && angle > 45)
		direction = RIGHT;
	if (angle <= 235 && angle > 135)
		direction = DOWN;
	if (angle <= 315 && angle > 235)
		direction = LEFT;

	printf("directions: %i, %i\n", dir_x, dir_y);

	next_square[0] = scene->player_position[0];
	next_square[1] = scene->player_position[1];
	// while(!ray_collision(scene, next_square))
	// {
		printf("initial square: %i, %i\n", next_square[0], next_square[1]);
		next_square[0] = find_next(next_square, scene->map_square_scale, dir_x);
		next_square[1] = find_next(next_square, scene->map_square_scale, dir_y);
		printf("next square: %i, %i\n", next_square[0], next_square[1]);
		printf("distance x:%i\ndistance y: %i\n", ft_abs(scene->player_position[0] - next_square[0]), ft_abs(scene->player_position[1] - next_square[1]));
		if (ft_abs(scene->player_position[0] - next_square[0]) >= ft_abs(scene->player_position[1] - next_square[1]))
			next_square[0] = cos(degr_to_rad(angle)) * scene->player_position[1]; //scene->player_position[0];
		else if (ft_abs(scene->player_position[0] - next_square[0]) <= ft_abs(scene->player_position[1] - next_square[1]))
			// next_square[1] = sin(degr_to_rad(angle)) * scene->player_position[1];
		printf("new_square: %i, %i\n\n", next_square[0], next_square[1]);

		
	// }
	

	
	int scale = 0.25 * map_scale(scene->map_size);
	// printf("scale: %i\n", scale);

	next_square[0] *= scale;
	next_square[1] *= scale;
	next_square[0] /= scene->map_square_scale;
	next_square[1] /= scene->map_square_scale;
	printf("scaled to: %i, %i\n\n\n", next_square[0], next_square[1]);

	
	// my_mlx_pixel_put(scene->image, next_square[0], next_square[1], COLOR_MAP_PLAYER);

	int	player_tmp[2];
	player_tmp[1] = scale * scene->player_position[1] / scene->map_square_scale;
	player_tmp[0] = scale * scene->player_position[0] / scene->map_square_scale;
	
	printf("draw to: %i, %i\n\n\n", next_square[0], next_square[1]);
	my_mlx_pixel_put(scene->image, next_square[0], next_square[1], COLOR_MAP_PLAYER);
	draw_line(scene->image, player_tmp, next_square, COLOR_MAP_PLAYER);
	distance = (int) sqrt (pow (next_square[0], 2) + pow(next_square[1], 2));
	return (distance);
} */

// V.x = cos(A)
// V.y = sin(A)