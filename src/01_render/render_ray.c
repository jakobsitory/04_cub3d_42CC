/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:03:37 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 12:54:10 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define HALT		0
#define FRWD		1
#define BACK		-1
#define COLOR_GREEN	0x0020fc03
#define COLOR_BLUE	0x00003cff
/** 
 * @brief Checks wether a ray in a given direction has hit a wall
 * @param scene main data structure including map data
 * @param pos current position (x,y) of the ray on the map
 * @param dir direction the ray (x,y) is heading to
 * @return 1 if wall has been hit, 0 if it has not hit a wall
 */
int	ray_collision(char **map, float dest[2], int dir[2])
{
	float	new_pos[2];

	new_pos[0] = dest[0];
	new_pos[1] = dest[1];
	if (dir[0] == FRWD && !is_whole_number(new_pos[0]))
		new_pos[0] = floorf(dest[0]);
	else if (dir[0] == BACK && is_whole_number(new_pos[0]))
		--new_pos[0];
	else if (dir[0] == BACK)
		new_pos[0] = floorf(dest[0]);
	if (dir[1] == FRWD && !is_whole_number(new_pos[1]))
		new_pos[1] = floorf(dest[1]);
	else if (dir[1] == BACK && is_whole_number(new_pos[1]))
		--new_pos[1];
	else if (dir[1] == BACK)
		new_pos[1] = floorf(dest[1]);
	if (map[(int) new_pos[1]][(int) new_pos[0]] == '1')
		return (1);
	return (0);
}

/**
 * @brief Search for next square on map of squares with given scale,
 *       from a start position in a certain direction
 * @param start position on the map from where to start
 * @param square_scale scale of one square
 * @param dir direction where to look for the next square
 */
void	find_next(float start[2], int dir[2])
{
	if (dir[0] != HALT)
	{
		if (dir[0] == FRWD && is_whole_number(start[0]))
			++start[0];
		else if (dir[0] == FRWD)
			start[0] = ceilf(start[0]);
		else if (dir[0] == BACK && is_whole_number(start[0]))
			--start[0];
		else if (dir[0] == BACK)
			start[0] = floorf(start[0]);
	}
	if (dir[1] != HALT)
	{
		if (dir[1] == FRWD && is_whole_number(start[1]))
			++start[1];
		else if (dir[1] == FRWD)
			start[1] = ceilf(start[1]);
		else if (dir[1] == BACK && is_whole_number(start[1]))
			--start[1];
		else if (dir[1] == BACK)
			start[1] = floorf(start[1]);
	}
}
/**
 * Sets the direction of movement based on the given angle. The direction is determined for both the x-axis (dir[0]) and y-axis (dir[1])
 * based on the angle's relation to cardinal directions. Directions are defined as forward (FRWD), backward (BACK), or halt (HALT).
 * 
 * @param dir An array of two integers where the direction will be stored.
 * @param angle The angle in degrees based on which the direction is set.
 */
void	set_direction(int dir[2], float angle)
{
	if (angle < 180)
		dir[0] = FRWD;
	if (angle > 180)
		dir[0] = BACK;
	if (angle == 0 || angle == 180 || angle == 360)
		dir[0] = HALT;
	if (angle < 90 || angle > 270)
		dir[1] = BACK;
	if (angle > 90 && angle < 270)
		dir[1] = FRWD;
	if (angle == 90 || angle == 270)
		dir[1] = HALT;
}
/**
 * Casts a single ray from the player's position in the specified direction until it collides with a wall. The function calculates
 * the next point along the ray's path based on the direction and checks for collision at each step. The direction is determined by
 * the angle parameter and adjusted for the game's coordinate system. The distance and final position of the ray are stored in the
 * provided t_ray_result structure.
 * 
 * @param ray Pointer to a t_ray_result structure where the result will be stored.
 * @param env Pointer to the t_env structure containing environment and game state information.
 * @param angle The angle in degrees at which the ray is cast.
 * @return 0 on successful execution.
 */
int	cast_ray(t_ray_result *ray, t_env *env, float angle)
{
	float	next[2];
	int		dir[2];
	float	diff[2];

	set_direction(dir, angle);
	vector_cpy(next, env->player_position);
	while (dir[0] * dir[1] == HALT && !ray_collision(env->map, next, dir))
		find_next(next, dir);
	while (!ray_collision(env->map, next, dir))
	{
		find_next(next, dir);
		diff[0] = (next[0] - env->player_position[0]);
		diff[1] = (next[1] - env->player_position[1]);
		if (ft_absf(diff[0] / sinf(degr_to_rad(angle))) \
				< ft_absf(diff[1] / cosf(degr_to_rad(angle))))
			next[1] = ft_absf(ft_absf(diff[0] / tanf(degr_to_rad(angle))) \
						+ dir[1] * env->player_position[1]);
		else
			next[0] = ft_absf(ft_absf(diff[1] * tanf(degr_to_rad(angle))) \
						+ dir[0] * env->player_position[0]);
	}
	ray->x = next[0];
	ray->y = next[1];
	ray->distance = get_distance(env->player_position, next);
	return (0);
}
/**
 * Renders rays for each vertical slice of the game window by casting rays from the player's position in the direction of the player's
 * orientation. The function adjusts the initial casting angle based on the player's field of view (FOV) and iterates over each
 * vertical slice, casting a ray and storing the result in the provided rays array.
 * 
 * @param rays An array of pointers to t_ray_result structures where the results of the ray casting will be stored.
 * @param env Pointer to the t_env structure containing environment and game state information, including the player's orientation.
 * @return 0 if all rays are successfully cast, 1 if an error occurs during ray casting.
 */
int	render_rays(t_ray_result **rays, t_env *env)
{
	float	angle;
	int		i;

	if (env->player_orientation > .5f * PLAYER_FOV)
		angle = (float)((int)(env->player_orientation - .5 * PLAYER_FOV) % 360);
	else
		angle = (float)(360.0f - .5f * PLAYER_FOV) + (env->player_orientation);
	i = 0;
	while (i < WINDOW_W)
	{
		angle += env->degr_per_ray;
		if (angle >= 360)
			angle -= 360;
		if (cast_ray(rays[i], env, angle))
			return (1);
		rays[i]->degree = angle;
		i++;
	}
	return (0);
}
