/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:23:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/10 20:05:49 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h> 
# include <string.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include "../libft/get_next_line.h"

//////////////////////////////-----STRUCTURES-----//////////////////////////////

typedef struct res
{
	char	*north_text_path;
	char	*east_text_path;
	char	*south_text_path;
	char	*west_text_path;
	int		floor_colors[3];
	int		ceiling_colors[3];
	int		floor_hex;
	int		ceiling_hex;
}	t_res;

typedef struct map
{
	char		*map_string;
	int			map_size[2];
	int			map_square_scale;
	char		**map;
	char		**map_copy;
	int			player_position[2];
	int			player_orientation;
	int			*x_moves;
	int			*y_moves;
}	t_map;


typedef struct data
{
	int		fd;
	char	*filepath;
	t_res	*res;
	char	*line;
	t_map	*map;
}	t_data;

/////////////////////////////////-----MAIN-----/////////////////////////////////

int		main(int argc, char *argv[]);
void	check_args(int argc, char **argv);

///////////////////////////////-----INIT DATA-----//////////////////////////////

t_data	*init_data(void);
int		*create_possible_moves_x(t_data *data);
int		*create_possible_moves_y(t_data *data);

////////////////////////////////-----UTILS-----/////////////////////////////////

void	exit_error(char *msg, t_data *data);
void	print_res(t_res *res);
void	free_data(t_data *data);
void	print_string_array(char **array);
void	print_map(t_map *map);

////////////////////////////////-----PARSE-----/////////////////////////////////

void	parse_file(t_data *data, char *filepath);

///////////////////////////-----PARSE TEXTURES-----/////////////////////////////

void	parse_textures(t_data *data);
void	save_identifier(char *identifier, char *line, t_data *data);
void	check_texture_file(char *path, t_data *data);
char	*remove_whitespace(char *src, t_data *data);

////////////////////////////-----PARSE COLORS-----//////////////////////////////

void	parse_colors(t_data *data);
void	save_color(char *identifier, char *line, t_data *data);
char	*save_next_hex(char *line, int *array, t_data *data);
int		valid_chars_color(char *str, t_data *data);
void	valid_number_format(char *str, t_data *data);
void	check_hex_range(t_data *data);
int		convert_to_hex(int rgb[3]);

/////////////////////////////-----PARSE MAP-----/////////////////////////////////

void	parse_map(t_data *data);
int		is_valid_map_line(char *line);
void	calc_no_lines(t_map *map);
void	calc_line_length(t_map *map);
char	**init_map(t_data *data);
char	**create_map_arr(t_data *data, int i, int j, int k);
void	read_map(t_data *data);
void	get_player_pos(t_data *data);
void	get_player_orientation(t_data *data);

///////////////////////////////-----MAP_CHECK-----//////////////////////////////

void	check_map(t_data *data);
void	flood_fill(t_data *data, char **map, int x, int y);
int		is_valid_pos(char **map, int x, int y);
int		check_valid_chars(char **map);
int		is_valid_char(char c);

////////////////////////////////-----DEFINES-----///////////////////////////////

# define USAGE_ERR "Correct Usage: [./cub3d xxx.cub]\n"
# define FILE_ERR "Unable to locate or read file\n"
# define TEXTURE_ERR "Unable to locate or read texture file\n"
# define COLOR_ERR "Invalid Color Definition\n"
# define MALLOC_ERR "Failed to allocate memory\n"
# define MISSING_EL "Missing Element in map\n"
# define CHARS_ERR "Invalid Chars in map\n"
# define SURR_ERR "Map not surrounded by walls\n"
# define MAP_ERR "Invalid map\n"


# define NORTH_ID "NO "
# define EAST_ID "EA "
# define SOUTH_ID "SO "
# define WEST_ID "WE "
# define FLOOR_ID "F "
# define CEILING_ID "C "


#endif