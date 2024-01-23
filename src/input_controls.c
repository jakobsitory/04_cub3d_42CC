/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 09:35:27 by jschott           #+#    #+#             */
/*   Updated: 2024/01/23 10:35:44 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"


void	img_update(t_scene *scene)
{
	//t_image	*img_temp;

	//img_temp = scene->image;
	//scene->image = (void *) malloc (sizeof(t_image));
	//if (!scene->image)
	//	return ; // ERROR MGMT
	//scene->image->img = mlx_new_image(scene->window->mlx, WINDOW_W, WINDOW_H);
	//scene->image->line_length = 100;
	/*scene->image->addr = mlx_get_data_addr(scene->image->img, \
											&scene->image->bits_per_pixel, \
											&scene->image->line_length, \
											&scene->image->endian);
	*/
	cast_all_rays(scene);
	prepare_rays(scene);
	
	/* Draw Scene */
	background_fill(scene);
	// draw_walls(scene);
	draw_map(scene);
	
	mlx_put_image_to_window(scene->window->mlx, scene->window->mlx_win, \
							scene->image->img, 0, 0);
	//mlx_destroy_image(scene->window->mlx, img_temp->img);
	//free (img_temp);
}

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
	// set_direction(scene->player_direction, scene->player_orientation);
	img_update(scene);
}

int	collision(t_scene *scene, int keycode)
{
	float	new_pos[2];

	new_pos[0] = scene->player_position[0];
	new_pos[1] = scene->player_position[1];
	if (keycode == MOVE_FRWD)
		new_pos[1] -= scene->player_speed;
	if (keycode == MOVE_BACK)
		new_pos[1] += scene->player_speed;
	if (keycode == MOVE_LEFT)
		new_pos[0] -= scene->player_speed;
	if (keycode == MOVE_RIGHT)
		new_pos[0] += scene->player_speed;
	if (scene->map[(int)new_pos[1]][(int)new_pos[0]] == '1')
		return (1);
	return (0);
}

void	update_position(t_scene *scene, int keycode)
{
	if (!scene || collision(scene, keycode))
		return ;
	if (keycode == MOVE_FRWD)
		scene->player_position[1] -= scene->player_speed;
	if (keycode == MOVE_LEFT)
		scene->player_position[0] -= scene->player_speed;
	if (keycode == MOVE_RIGHT)
		scene->player_position[0] += scene->player_speed;
	if (keycode == MOVE_BACK)
		scene->player_position[1] += scene->player_speed;
	img_update(scene);
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
