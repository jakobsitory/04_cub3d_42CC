/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:35:27 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 15:36:08 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	win_close(t_window *window)
{
	mlx_loop_end (window->mlx);
	return (0);
}

int	keypress(int keycode, t_data *data)
{
	t_window	*window;

	window = data->window;
	if (keycode == ESCAPE)
		return (win_close (window));
	if (keycode == LOOK_LEFT || keycode == LOOK_RIGHT)
		render_player_orienation(data->env, keycode);
	if (keycode == MOVE_BACK || keycode == MOVE_FRWD || \
		keycode == MOVE_RIGHT || keycode == MOVE_LEFT)
		render_player_position(data->env, keycode);
	else
		return (0);
	render_frame(data->rays, data->env);
	return (0);
}

void	event_hooks(t_data *data)
{
	mlx_hook(data->window->mlx_win, 17, 1L << 0, win_close, data->window);
	mlx_hook(data->window->mlx_win, 2, 1L << 0, keypress, data);
}
