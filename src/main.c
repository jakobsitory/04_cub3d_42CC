/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:22:00 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/24 17:54:09 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_env(t_env *env)
{
	printf("north txt: %s\n", env->wall_textures[0]->filepath);
	printf("east txt: %s\n", env->wall_textures[1]->filepath);
	printf("south txt: %s\n", env->wall_textures[2]->filepath);
	printf("west txt: %s\n", env->wall_textures[3]->filepath);
	print_string_array(env->map);
	printf("map size: %i x %i\n", env->map_size[0], env->map_size[1]);
	printf("player position: %f x %f\n", env->player_position[0], env->player_position[1]);
	printf("player orientation: %i\n", env->player_orientation);
	printf("floor hex: %x\n", env->floor_hex);
	printf("ceiling hex -> %x\n", env->ceiling_hex);
}

int	main(int argc, char *argv[])
{
	//t_scene	*scene;
	t_data	*data;
	
	check_args(argc, argv);
	data = (t_data *)malloc (sizeof(t_data));
	data = init_data();
	parse_file(data, argv[1]);
	print_env(data->env);

	data->window = init_window();
	printf("img_address: %p\n", &data->window->img_addr);
	data->rays = init_rays();
	render_frame(data->rays, data->env);
	draw_frame(data);
	event_hooks(data);
	mlx_loop(data->window->mlx);

	// win_destroy(scene); */
	free_data(data);
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
