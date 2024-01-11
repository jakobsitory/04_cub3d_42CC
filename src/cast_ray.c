/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:03:37 by jschott           #+#    #+#             */
/*   Updated: 2024/01/11 19:54:37 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

#define HALT 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define COLOR_GREEN 0x0020fc03
#define COLOR_BLUE 0x00003cff

int	ray_collision(t_scene *scene, int pos[2], int dir_x, int dir_y)
{
	int	new_pos[2];

	new_pos[0] = pos[0];
	new_pos[1] = pos[1];
	if (dir_x == RIGHT)
		new_pos[0] = new_pos[0] + 1;
	if (dir_x == LEFT)
		new_pos[0] = new_pos[0] - 1;
	if (dir_y == DOWN)
		new_pos[1] = new_pos[1] + 1;
	if (dir_y == UP)
		new_pos[1] = new_pos[1] - 1;
	new_pos[0] /= scene->map_square_scale;
	new_pos[1] /= scene->map_square_scale;
	if (scene->map[new_pos[1]][new_pos[0]] == '1')
		return (1);
	return (0);
}

/* int	find_next (int start[2], int square_scale, int dir) // REPLACE DIR WITH ANG?
{
	int	distance;

	if (dir == UP || dir == DOWN)
		distance = start[1];
	else if (dir == LEFT || dir == RIGHT)
		distance = start[0];
	if (dir == HALT)
		return (distance);
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
printf("%i ", distance);
	return (distance);
} */

int	find_next (int start, int square_scale, int dir) // REPLACE DIR WITH ANG?
{
	int	distance;

	distance = start;
	if (dir == HALT)
		return (distance);
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
printf("%i ", distance);
	return (distance);
}

int	cast_ray(t_scene *scene, int angle)
{
	float	distance = 0;
	int 	*next_square;
	int		square_0[2];
	int		square_1[2];
	int		dir_x;
	int		dir_y;

	if (angle < 180)
		dir_x = RIGHT;
	if (angle > 180)
		dir_x = LEFT;
	if (angle == 0 || angle == 180 || angle == 360)
		dir_x = HALT;
	if (angle < 90 || angle > 270)
		dir_y = UP;
	if (angle > 90 && angle < 270)
		dir_y = DOWN;
	if (angle == 90 || angle == 270)
		dir_y = HALT;
	printf("angle: %i\ndirections: %i, %i\n", angle, dir_x, dir_y);
	next_square = scene->player_position;
	printf("\ninitial square: %i, %i\n", next_square[0], next_square[1]);
	while(1)
	{
		square_0[0] = next_square[0];
		square_0[1] = next_square[1];
		square_1[0] = next_square[0];
		square_1[1] = next_square[1];
		

		int offset_x;
		int offset_y;

		offset_x = scene->player_position[0];
		if (dir_x == LEFT)
			offset_x *= -1;
		offset_y = scene->player_position[1];
		if (dir_y == UP)
			offset_y *= -1;

		square_0[1] = find_next(square_0[1], scene->map_square_scale, dir_y);
		if (dir_y == HALT && dir_x == LEFT)
			square_0[0] = scene->player_position[0]; //scene->map_square_scale;
		else if (dir_y == HALT && dir_x == RIGHT)
			square_0[0] = (scene->map_size[0] - 1) * scene->map_square_scale;
		else
			square_0[0] = ft_abs((float) ft_abs(ft_abs(square_0[1] - scene->player_position[1]) \
							* tanf(degr_to_rad(angle))) + scene->player_position[0]);
							/* printf("square_0: \t%f,\t", (float) \
											(ft_abs(square_0[1] - scene->player_position[1]) \
											* tanf(degr_to_rad(angle)) + scene->player_position[0])); */
							// printf("%i\n", square_0[1]);
							// printf("\t\t%i,\t\t%i\n", square_0[0], square_0[1]);
		
		square_1[0] = find_next(square_1[0], scene->map_square_scale, dir_x);
		if (dir_x == HALT && dir_y == UP)
			square_1[1] = scene->map_square_scale;
		else if (dir_x == HALT && dir_y == DOWN)
			square_1[1] = (scene->map_size[1] - 1) * scene->map_square_scale;
		else
			square_1[1] = ft_abs((float) (ft_abs(square_1[0] - scene->player_position[0])) \
							/ tanf(degr_to_rad(angle)) - scene->player_position[1]);

							// printf("square_1: \t%i,\t\t", square_1[0]);
							/* printf("%d\n", ft_abs ((float) \
										(square_1[0] - scene->player_position[0]) \
										* tanf(degr_to_rad(angle)) + scene->player_position[1])); */
							// printf("\t\t%i,\t\t%i\n", square_1[0], square_1[1]);
							/* printf("distance A:\t%f\ndistance B:\t%f\n", \
										get_distance(scene->player_position, square_0),\
										get_distance(scene->player_position, square_1)); */
		printf("square_0:\t%i, %i\n", square_0[0], square_0[1]);
		printf("square_1:\t%i, %i\n\n", square_1[0], square_1[1]);
	
		if((get_distance(scene->player_position, square_0) \
			<= get_distance(scene->player_position, square_1)))
			next_square = square_0;
		else //if (!((int) get_distance(scene->player_position, square_0)))
			next_square = square_1;
		// printf("new square:\t%i, %i\n\n", next_square[0], next_square[1]);
		if (ray_collision(scene, next_square, dir_x, dir_y))
			break ;
	}
	distance = get_distance(scene->player_position, next_square);
/* 	printf("\nPLAYER DATA\nposition:\t%i, %i\norientation:\t%i\nwall:\t\t%i, %i\ndistance:\t%f\n", \
			scene->player_position[0], scene->player_position[1], scene->player_orientation, next_square[0], next_square[1], distance);
*/
/* 	printf("square_0:\t%i, %i\nsquare_1:\t%i, %i\nnext_square:\t%i, %i\n\n",\
		square_0[0],\
		square_0[1],\
		square_1[0],\
		square_1[1],\
		next_square[0],\
		next_square[1]);
*/
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

	int color;
	if (angle < 90)
		color = COLOR_BLUE;
	if (angle > 90 && angle < 180)
		color = COLOR_GREEN;
	if (angle > 180 && angle < 270)
		color = COLOR_MAP_PLAYER;
	if (angle > 270 && angle < 360)
		color = COLOR_FLOOR;
	
	draw_line(scene->image, player_tmp, next_square, color);
	return ((int) distance);
}
