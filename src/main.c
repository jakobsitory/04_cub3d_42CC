/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:22:00 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/24 17:20:00 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char **test_map(void)
{
    int i, j;
    char **map = malloc(sizeof(char *) * 8);
    if (!map)
        return NULL;

    for (i = 0; i < 8; i++)
    {
        map[i] = malloc(sizeof(char) * 9); // 8 for map size and 1 for null-terminator
        if (!map[i])
            return NULL;

        for (j = 0; j < 8; j++)
        {
            if (i == 0 || i == 7 || j == 0 || j == 7)
                map[i][j] = '1'; // Wall
            else
                map[i][j] = '0'; // Floor
        }
        map[i][j] = '\0'; // Null-terminator for string
    }

    return map;
}

int	main(int argc, char *argv[])
{
	t_data	*data;
	
	// check_args(argc, argv);
	data = (t_data *)malloc (sizeof(t_data));
	data = init_data();
	// parse_file(data, argv[1]);
	//free_data(data);

	// data->env = init_env(map);
	// data->window = init_window();
	// data->rays = init_rays();

	data->env->map = test_map();

	// printf("img_address: %s\n", data->window->img_addr);


	render_frame(data->rays, data->env);
	draw_frame(data);
	event_hooks(data);
	printf("BYE\n");
	mlx_loop(data->window->mlx);

	free_data(data);
	printf("%s, %i", argv[0], argc);
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
