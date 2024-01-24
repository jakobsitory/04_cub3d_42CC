/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:35:27 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 08:38:33 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	win_close(t_window *window)
{
	mlx_loop_end (window->mlx);
	return (0);
}

void	update_orienation(t_scene *scene, int keycode)
{
	if (keycode == LOOK_LEFT)
		scene->player_orientation -= 2;
	if (keycode == LOOK_RIGHT)
		scene->player_orientation += 2;
	if (scene->player_orientation < 0)
		scene->player_orientation += 360;
	scene->player_orientation %= 360;
	draw_frame(scene);
}

void	update_position(t_scene *scene, int keycode)
{
	float	angle;
	int		dir[2];
	float	new_pos[2];

	angle = scene->player_orientation;
	new_pos[0] = scene->player_position[0];
	new_pos[1] = scene->player_position[1];
	if (keycode == MOVE_FRWD)
		angle -= 90;
	if (keycode == MOVE_BACK)
		angle += 90;
	if (keycode == MOVE_LEFT)
		angle += 180;
	set_direction(dir, angle);
	new_pos[0] += cosf(degr_to_rad(angle)) * scene->player_speed;
	new_pos[1] += sinf(degr_to_rad(angle)) * scene->player_speed;
	if (scene->map[(int)new_pos[1]][(int)new_pos[0]] == '1')
		return ;
	scene->player_position[0] = new_pos[0];
	scene->player_position[1] = new_pos[1];
	draw_frame(scene);
}

int	keypress(int keycode, t_scene *scene)
{
	t_window	*window;

	window = scene->window;
	if (keycode == ESCAPE)
		return (win_close (window));
	if (keycode == LOOK_LEFT || keycode == LOOK_RIGHT)
		update_orienation(scene, keycode);
	if (keycode == MOVE_BACK || keycode == MOVE_FRWD || \
		keycode == MOVE_RIGHT || keycode == MOVE_LEFT)
		update_position(scene, keycode);
	return (0);
}

void	key_events(t_scene *scene)
{
	mlx_hook(scene->window->mlx_win, 17, 1L << 0, win_close, scene->window);
	mlx_hook(scene->window->mlx_win, 2, 1L << 0, keypress, scene);
}
