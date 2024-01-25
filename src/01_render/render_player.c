/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:25:24 by jschott           #+#    #+#             */
/*   Updated: 2024/01/25 12:00:26 by jschott          ###   ########.fr       */
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
}

void	render_player_position(t_env *env, int keycode)
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
}
