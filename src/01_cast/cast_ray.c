/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:03:37 by jschott           #+#    #+#             */
/*   Updated: 2024/01/23 17:24:06 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#define HALT		0
#define FRWD		1
#define BACK		-1
#define COLOR_GREEN	0x0020fc03
#define COLOR_BLUE	0x00003cff

/// @brief Checks wether a ray in a given direction has hit a wall
/// @param scene main data structure including map data
/// @param pos current position (x,y) of the ray on the map
/// @param dir direction the ray (x,y) is heading to
/// @return 1 if wall has been hit, 0 if it has not hit a wall
int	ray_collision(t_scene *scene, float dest[2], int dir[2])
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
		new_pos[1]= floorf(dest[1]);
	else if (dir[1] == BACK && is_whole_number(new_pos[1]))
		--new_pos[1];
	else if (dir[1] == BACK)
		new_pos[1] = floorf(dest[1]);
	if (scene->map[(int) new_pos[1]][(int) new_pos[0]] == '1')
		return (1);
	return (0);
}

/// @brief Search for next square on map of squares with given scale,
///        from a start position in a certain direction
/// @param start position on the map from where to start
/// @param square_scale scale of one square
/// @param dir direction where to look for the next square
/// @return 
void	find_next(float start[2], int dir[2])
{
	if (dir[0] != HALT)
	{
		if (dir[0] == FRWD && is_whole_number(start[0]))
			++start[0];
		else if (dir[0] == FRWD)
			start[0] = ceilf(start[0]);
		else if (dir[0] == BACK && is_whole_number(start[0]))
			--start[0]; // = floorf(start[0]);
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

int	cast_ray(t_ray_result *ray,  t_scene *scene, float angle)
{
	float	next[2];
	int		dir[2];
	float	diff[2];

	set_direction(dir, angle);
	next[0] = scene->player_position[0];
	next[1] = scene->player_position[1];
	while (!ray_collision(scene, next, dir))
	{
		find_next(next, dir);
		if (dir[0] != HALT && dir[1] != HALT)
		{
			diff[0] = (next[0] - scene->player_position[0]);
			diff[1] = (next[1] - scene->player_position[1]);
			if (ft_absf(diff[0] / sinf(degr_to_rad(angle))) \
					< ft_absf(diff[1] / cosf(degr_to_rad(angle))))
				next[1] = ft_absf(ft_absf(diff[0] / tanf(degr_to_rad(angle))) \
							+ dir[1] * scene->player_position[1]);
			else
				next[0] = ft_absf(ft_absf(diff[1] * tanf(degr_to_rad(angle))) \
							+ dir[0] * scene->player_position[0]);
		}
	}
	ray->distance = get_distance(scene->player_position, next);
	ray->x = next[0];
	ray->y = next[1];
	ray->degree = angle;
	return (0);
}

void	cast_all_rays(t_scene *scene)
{
	float	angle;
	int		i;

	if (scene->player_orientation > .5f * FOV)
		angle = (float)((int)(scene->player_orientation - .5f * FOV)  % 360);
	else
		angle = (float)(360.0f - .5f * FOV) + ((scene->player_orientation));
	i = 0;
	while (i < WINDOW_W)
	{
		angle += scene->ray_resolution;
		if (angle >= 360)
			angle -= 360;
		cast_ray(scene->rays[i], scene, angle);
		i++;
	}
}

