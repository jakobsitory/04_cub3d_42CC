/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:03:37 by jschott           #+#    #+#             */
/*   Updated: 2024/01/19 15:48:09 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

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
int	ray_collision(t_scene *scene, int pos[2], int dir[2])
{
	int	new_pos[2];

	new_pos[0] = pos[0];
	new_pos[1] = pos[1];
	// printf("checking: %i, %i\n", new_pos[1], new_pos[0]);
	if (dir[0] == FRWD)
		++new_pos[0];
	if (dir[0] == BACK)
		--new_pos[0];
	if (dir[1] == FRWD)
		++new_pos[1];
	if (dir[1] == BACK)
		--new_pos[1];
	new_pos[0] /= scene->map_square_scale;
	new_pos[1] /= scene->map_square_scale;
	// printf("collision: %i, %i\n", new_pos[1], new_pos[0]);
	if (scene->map[new_pos[1]][new_pos[0]] == '1')
		return (1);
	return (0);
}

/// @brief Search for next square on map of squares with given scale,
///        from a start position in a certain direction
/// @param start position on the map from where to start
/// @param square_scale scale of one square
/// @param dir direction where to look for the next square
/// @return 
int	find_next(int start[2], int square_scale, int dir[2])
{
	while (dir[0] != HALT)
	{
		if (dir[0] == FRWD)
			++start[0];
		if (dir[0] == BACK)
			--start[0];
		if (0 == start[0] % square_scale)
			break ;
	}
	while (dir[1] != HALT)
	{
		if (dir[1] == FRWD)
			++start[1];
		if (dir[1] == BACK)
			--start[1];
		if (0 == start[1] % square_scale)
			break ;
	}
	return (0);
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
	int		next_square[2];
	int		dir[2];

	set_direction(dir, angle);
	next_square[0] = scene->player_position[0];
	next_square[1] = scene->player_position[1];
	while(1)
	{
		find_next(next_square, scene->map_square_scale, dir);
		if (dir[0] != HALT && dir[1] != HALT)
		{
			if (ft_absf((float) ft_abs(next_square[0] - scene->player_position[0]) / sinf(degr_to_rad(angle))) \
				< ft_absf((float) ft_abs(next_square[1] - scene->player_position[1]) / cosf(degr_to_rad(angle))))
				next_square[1] = ft_abs((float) ft_abs(ft_abs(next_square[0] - scene->player_position[0]) \
					/ tanf(degr_to_rad(angle))) + dir[1] * scene->player_position[1]);
			else
				next_square[0] = ft_abs((float) ft_abs(ft_abs(next_square[1] - scene->player_position[1]) \
							* tanf(degr_to_rad(angle))) + dir[0] * scene->player_position[0]);
		}
		if (ray_collision(scene, next_square, dir))
			break ;
	}
	ray->distance = get_distance(scene->player_position, next_square);
	ray->x = next_square[0]  / 10.0;
	ray->y = next_square[1] / 10.0;
	ray->degree = angle;
	get_texture(ray);
	return (0);
}

void	cast_all_rays(t_scene *scene)
{
	float	angle;
	int		i;

	angle = (float)((int)(scene->player_orientation - .5 * FOV)  % 360);
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

