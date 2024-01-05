/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:35:27 by jschott           #+#    #+#             */
/*   Updated: 2024/01/05 16:55:50 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

int	win_close(t_window *window)
{
	mlx_loop_end (window->mlx);
	return (0);
}

void	update_orienation(t_scene *scene, int keycode)
{
	if (keycode == LOOK_LEFT)
		scene->player_orientation += 1;
	if (keycode == LOOK_RIGHT)
		scene->player_orientation -= 1;
	scene->player_orientation %= 360;
	scene->player_orientation = ft_abs(scene->player_orientation);
	ft_printf("orientation: %i\n", scene->player_orientation);
}

void	update_position(t_scene *scene, int keycode)
{
	if (!scene)
		return ;
	if (keycode == MOVE_FRWD)
		ft_printf("moving forward\n");
	if (keycode == MOVE_LEFT)
		ft_printf("moving left\n");
	if (keycode == MOVE_RIGHT)
		ft_printf("moving right\n");
	if (keycode == MOVE_BACK)
		ft_printf("moving back\n");
	// img_update(scene);
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
