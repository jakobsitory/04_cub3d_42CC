/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:25:24 by jschott           #+#    #+#             */
/*   Updated: 2024/01/25 15:34:36 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_player_orienation(t_env *env, int keycode)
{
	if (keycode == LOOK_LEFT)
		env->player_orientation -= 2;
	if (keycode == LOOK_RIGHT)
		env->player_orientation += 2;
	if (env->player_orientation < 0)
		env->player_orientation += 360;
	env->player_orientation %= 360;
	env->has_rotated = 1;
}

void	render_player_position(t_env *env, int keycode)
{
	float	angle;
	int		dir[2];
	float	new_pos[2];

	env->has_moved = 1;
	env->has_moved = 1;
	angle = env->player_orientation;
	new_pos[0] = env->player_position[0];
	new_pos[1] = env->player_position[1];
	if (keycode == MOVE_FRWD)
		angle -= 90;
	if (keycode == MOVE_BACK)
		angle += 90;
	if (keycode == MOVE_LEFT)
		angle += 180;
	set_direction(dir, angle);
	new_pos[0] += cosf(degr_to_rad(angle)) * PLAYER_SPEED;
	new_pos[1] += sinf(degr_to_rad(angle)) * PLAYER_SPEED;
	if (env->map[(int)(new_pos[1] + dir[1] * PLAYER_SPEED)][(int)(new_pos[0] + dir[0] * PLAYER_SPEED)] == '1')
	{
		printf("%f %f\n", new_pos[0], new_pos[1]);
		env->has_moved = 0;
		return ;
	}
	env->player_position[0] = new_pos[0];
	env->player_position[1] = new_pos[1];
}

/* void	render_player_position(t_env *env, int keycode)
{
	float	angle;
	int		dir[2];
	float	new_pos[2];

	angle = env->player_orientation;
	new_pos[0] = env->player_position[0];
	new_pos[1] = env->player_position[1];
	if (keycode == MOVE_FRWD)
		angle -= 90;
	if (keycode == MOVE_BACK)
		angle += 90;
	if (keycode == MOVE_LEFT)
		angle += 180;
	set_direction(dir, angle);
	new_pos[0] += cosf(degr_to_rad(angle)) * PLAYER_SIZE;
	new_pos[1] += sinf(degr_to_rad(angle)) * PLAYER_SIZE;
	if (env->map[(int)new_pos[1]][(int)new_pos[0]] == '1')
		return ;
	env->player_position[0] = new_pos[0];
	env->player_position[1] = new_pos[1];
} */