/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:06:18 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/01 20:50:22 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_parser(t_data *data)
{
	data->parser = malloc(sizeof(t_parser));
	if (!data->parser)
		exit_error(MALLOC_ERR, data);
	data->parser->line = NULL;
	data->parser->line_trimmed = NULL;
	data->parser->map_string = ft_strdup("");
	data->parser->map_copy = NULL;
	data->parser->north_text_path = NULL;
	data->parser->east_text_path = NULL;
	data->parser->south_text_path = NULL;
	data->parser->west_text_path = NULL;
	data->parser->ceiling_colors[0] = -1;
	data->parser->ceiling_colors[1] = -1;
	data->parser->ceiling_colors[2] = -1;
	data->parser->floor_colors[0] = -1;
	data->parser->floor_colors[1] = -1;
	data->parser->floor_colors[2] = -1;
	data->parser->x_moves = create_possible_moves_x(data);
	data->parser->y_moves = create_possible_moves_y(data);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *) malloc(sizeof(t_data));
	if (!data)
		exit_error(MALLOC_ERR, data);
	init_env(data);
	init_parser(data);
	data->rays = init_rays(data);
	data->window = init_window(data);
	return (data);
}

void	init_env(t_data *data)
{
	data->env = malloc(sizeof(t_env));
	if (!data->env)
		exit_error(MALLOC_ERR, data);
	data->env->wall_textures = malloc (sizeof(t_xpm *) * 4);
	if (!data->env->wall_textures)
		exit_error(MALLOC_ERR, data);
	data->env->background_hex = malloc ((WINDOW_W * WINDOW_H) * sizeof(int));
	if (!data->env->background_hex)
		exit_error(MALLOC_ERR, data);
	data->env->wall_textures[0] = NULL;
	data->env->wall_textures[1] = NULL;
	data->env->wall_textures[2] = NULL;
	data->env->wall_textures[3] = NULL;
	data->env->map = NULL;
	data->env->ceiling_hex = -1;
	data->env->floor_hex = -1;
	data->env->degr_per_ray = (float) PLAYER_FOV / (float) WINDOW_W;
	data->env->player_has_moved = 1;
	data->env->player_has_rotated = 1;
}

t_xpm	*init_xpm(char *filename, t_data *data)
{
	t_xpm	*xpm;

	xpm = malloc(sizeof(t_xpm));
	if (!xpm)
		exit_error(MALLOC_ERR, data);
	xpm->filepath = ft_strdup(filename);
	xpm->colors = NULL;
	xpm->fd = open(filename, O_RDONLY);
	if (xpm->fd < 0)
		exit_error(TEXTURE_ERR, data);
	xpm->lines = NULL;
	xpm->rows = 0;
	xpm->columns = 0;
	xpm->colors_count = 0;
	xpm->bytes_per_pixel = 0;
	return (xpm);
}

char	**init_map(t_data *data)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * (data->env->map_size[1] + 1));
	if (!map)
		exit_error(MALLOC_ERR, data);
	while (i < data->env->map_size[1])
	{
		map[i] = malloc(sizeof(char) * (data->env->map_size[0] + 1));
		if (!map[i])
			exit_error(MALLOC_ERR, data);
		i++;
	}
	data->env->map_scale = map_scale(data->env->map_size);
	map[i] = NULL;
	return (map);
}
