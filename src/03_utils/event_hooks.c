/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:35:27 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 12:59:20 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Closes the game window and ends the main loop. This function is triggered by window close events or pressing the ESCAPE key.
 * It calls `mlx_loop_end` to terminate the main loop, effectively closing the game window.
 * 
 * @param window Pointer to the t_window structure containing window and MLX instance information.
 * @return Always returns 0.
 */
int	win_close(t_window *window)
{
	mlx_loop_end (window->mlx);
	return (0);
}

/**
 * Handles key press events for the game. This function is responsible for processing all key press inputs, such as movement
 * commands and orientation changes. It updates the player's position or orientation based on the key pressed and triggers
 * re-rendering of the frame if necessary.
 * 
 * @param keycode The code of the key that was pressed.
 * @param data Pointer to the t_data structure containing game data and settings.
 * @return Always returns 0.
 */
int	keypress(int keycode, t_data *data)
{
	t_window	*window;

	window = data->window;
	if (keycode == ESCAPE)
		return (win_close (window));
	else if (keycode == LOOK_LEFT || keycode == LOOK_RIGHT)
		render_player_orienation(data->env, keycode);
	else if (keycode == MOVE_BACK || keycode == MOVE_FRWD || \
		keycode == MOVE_RIGHT || keycode == MOVE_LEFT)
		render_player_position(data->env, keycode);
	if (data->env->player_has_moved || data->env->player_has_rotated)
	{
		render_frame(data);
		draw_frame(data);
		data->env->player_has_rotated = 0;
		data->env->player_has_moved = 0;
	}
	return (0);
}

/**
 * Sets up event hooks for window close and key press actions. This function registers callbacks for handling window close events
 * and key press inputs using the MiniLibX library functions `mlx_hook`. It ensures the game responds to these events for
 * controlling the game window and player actions.
 * 
 * @param data Pointer to the t_data structure containing game data and settings.
 */
void	event_hooks(t_data *data)
{
	mlx_hook(data->window->mlx_win, 17, 1L << 0, win_close, data->window);
	mlx_hook(data->window->mlx_win, 2, 1L << 0, keypress, data);
}
