/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   j_raycaster.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jschott <jschott@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/04 17:30:29 by jschott		   #+#	#+#			 */
/*   Updated: 2024/01/04 17:47:06 by jschott		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/j_cub3D.h"

char **init_map(void)
{
	int i, j;
	char **map = malloc(8 * sizeof(char *));

	if (map == NULL)
		return (NULL);

	for (i = 0; i < 8; i++)
	{
		map[i] = malloc(8 * sizeof(char));
		if (map[i] == NULL)
			return (NULL);
	}

	char temp[8][8] = {
		{'1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '1', '1', '0', '1'},
		{'1', '1', '1', 'N', '1', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1'}
	};

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			map[i][j] = temp[i][j];
	}

	return map;
}

int	main(void)
{
	t_scene	*scene;

	scene = (t_scene *) malloc (sizeof (t_scene));
	if (!scene)
		return (1);
	win_init(scene);

	scene->map = init_map();
	scene->map_size[0] = 8;
	scene->map_size[1] = 8;

	scene->rays = (t_ray_result **) malloc (FOV * sizeof(t_ray_result *));
	if (!scene->rays)
		return (1);
	for (int i = 0; i < FOV; i++)
		scene->rays[i] = (t_ray_result *) malloc (sizeof(t_ray_result));

	scene->map_square_scale = 100;

	scene->player_position[0] = (1.5 * scene->map_square_scale);
	scene->player_position[1] = (2.5 * scene->map_square_scale);
	scene->player_orientation = 180;

	background_fill(scene);
	draw_map(scene);
	for (int i = 0; i < 270; i++)
		cast_ray(scene, i);
	for (int i = 271; i < 360; i++)
		cast_ray(scene, i);
	// cast_ray(scene, scene->player_orientation);
/* 
	for (int i = 0; i< FOV; i++) {
		printf("rays[%i].degree = %i;\n", i, i);
		printf("rays[%i].distance = %f\n", i, scene->rays[i]->distance);
		printf("rays[%i].x = %f\n", i, scene->rays[i]->x);
		printf("rays[%i].y = %f\n", i, scene->rays[i]->y);
	} */

	mlx_put_image_to_window(scene->window->mlx, scene->window->mlx_win, \
							scene->image->img, 0, 0);
	key_events(scene);
	mlx_loop(scene->window->mlx);

	win_destroy(scene);
	return (0);
}
