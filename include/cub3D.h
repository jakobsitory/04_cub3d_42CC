/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:23:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/12 15:59:46 by lgrimmei         ###   ########.fr       */
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
void	init_res(t_data *data);
int		*create_possible_moves_x(t_data *data);
int		*create_possible_moves_y(t_data *data);
char	**init_map(t_data *data);

////////////////////////////////-----UTILS-----/////////////////////////////////

void	exit_error(char *msg, t_data *data);
void	print_res(t_res *res);
void	print_string_array(char **array);
void	print_map(t_map *map);

////////////////////////////////-----FREE-----/////////////////////////////////

void	free_data(t_data *data);
void	free_res(t_data *data);
void	free_str_arr(char **arr);
void	free_map(t_data *data);

////////////////////////////////-----PARSE-----/////////////////////////////////

void	parse_file(t_data *data, char *filepath);
void	check_invalid_lines(t_data *data);

///////////////////////////-----PARSE TEXTURES-----/////////////////////////////

void	parse_textures(t_data *data);
void	save_identifier(char *identifier, char *line, t_data *data);
void	check_texture_file(char *path, t_data *data);
char	*remove_whitespace(char *src, t_data *data);

////////////////////////////-----PARSE COLORS-----//////////////////////////////

void	parse_colors(t_data *data);
void	save_color(char *identifier, char *line, t_data *data);
void	check_color_saved(t_data *data, char *identifier);
char	*save_next_hex(char *line, int *array, t_data *data);
int		valid_chars_color(char *str, t_data *data);
void	valid_number_format(char *str, t_data *data);
void	check_hex_range(t_data *data);
int		convert_to_hex(int rgb[3]);

/////////////////////////////-----PARSE MAP-----////////////////////////////////

void	parse_map(t_data *data);
int		is_valid_map_line(char *line);
void	calc_map_size(t_map *map);
void	calc_no_lines(t_map *map);
void	calc_line_length(t_map *map);
char	**create_map_arr(t_data *data, int i, int j, int k);
void	read_map(t_data *data);
void	get_player_pos(t_data *data);
void	get_player_orientation(t_data *data);

/////////////////////////////-----PARSE HELP-----///////////////////////////////

void	parse_successful(t_data *data);
int		only_spaces(char *line);

///////////////////////////////-----MAP_CHECK-----//////////////////////////////

void	check_map(t_data *data);
void	flood_fill(t_data *data, char **map, int x, int y);
int		is_valid_pos(char **map, int x, int y);
int		check_valid_chars(char **map, t_data *data);
int		is_valid_char(char c);

////////////////////////////////-----DEFINES-----///////////////////////////////

# define USAGE_ERR "Correct Usage: [./cub3d xxx.cub]\n"
# define FILE_ERR "Unable to locate or read file\n"
# define TEXTURE_ERR "Unable to locate or read texture file\n"
# define COLOR_ERR "Invalid Color Definition\n"
# define MALLOC_ERR "Failed to allocate memory\n"
# define CHARS_ERR "Invalid Chars in map\n"
# define SURR_ERR "Map not surrounded by walls\n"
# define MAP_ERR "Invalid map\n"
# define MULTIPLE_TEXT "Multiple Definitions of Textures\n"
# define MULTIPLE_COLOR "Multiple Definitions of Colors\n"
# define ONLY_SPACES "Line with only spaces outside of map found\n"
# define INV_LINE "Invalid Line found\n"

# define NORTH_ID "NO "
# define EAST_ID "EA "
# define SOUTH_ID "SO "
# define WEST_ID "WE "
# define FLOOR_ID "F "
# define CEILING_ID "C "

#endif