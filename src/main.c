/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:22:00 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/24 12:21:43 by jschott          ###   ########.fr       */
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
	//free_data(data);

	scene = scene_init(data);
	win_init(scene);
	draw_frame(scene);
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
