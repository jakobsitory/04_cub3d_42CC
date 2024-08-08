/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:22:00 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/08/08 13:02:46 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * The main function of the game. It initializes the game data, parses the configuration file, renders the game frame, sets up event hooks, and starts the game loop.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @return Always returns 0.
 */
int	main(int argc, char *argv[])
{
	t_data	*data;

	check_args(argc, argv);
	data = init_data();
	parse_file(data, argv[1]);
	render_frame(data);
	render_background(data->env);
	draw_frame(data);
	event_hooks(data);
	mlx_loop(data->window->mlx);
	free_data(data);
	return (0);
}

/**
 * Validates the command-line arguments to ensure there is exactly one argument (the configuration file) and that it has a .cub extension.
 * 
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 */
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
