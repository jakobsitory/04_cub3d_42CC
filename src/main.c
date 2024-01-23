/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:22:00 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/23 17:32:18 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char *argv[])
{
	t_scene	*scene;
	t_data	*data;

	check_args(argc, argv);
	data = init_data();
	parse_file(data, argv[1]);
	scene = scene_init(data);
	win_init(scene);
	cast_all_rays(scene);
	prepare_rays(scene);
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

void	check_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		exit_error(USAGE_ERR, NULL);
	if (ft_strlen(argv[1]) <= 5)
		exit_error(USAGE_ERR, NULL);
	if (!(ft_strncmp(".cub", argv[1] + (ft_strlen(argv[1]) - 4), 4) == 0))
		exit_error(USAGE_ERR, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error(FILE_ERR, NULL);
	close(fd);
}
