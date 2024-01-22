/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_raycaster.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:00:33 by jschott           #+#    #+#             */
/*   Updated: 2024/01/22 12:29:06 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"

char **map_init(void)
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
		{'1', '0', '1', 'N', '1', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1'}
	};

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			map[i][j] = temp[i][j];
	}

	return map;
}

int	main(int argc, char *argv[])
{
	t_scene	*scene;
	t_data	*data;

	check_args(argc, argv);
	data = init_data();
	parse_file(data, argv[1]);
	free_data(data);

	scene = scene_init();
	win_init(scene);

	cast_all_rays(scene);
	prepare_rays(scene);
	
	/* Draw Scene */
	background_fill(scene);
	draw_walls(scene);
	draw_map(scene);
	mlx_put_image_to_window(scene->window->mlx, scene->window->mlx_win, \
							scene->image->img, 0, 0);
	key_events(scene);
	mlx_loop(scene->window->mlx);

	win_destroy(scene);
	return (0);
}
