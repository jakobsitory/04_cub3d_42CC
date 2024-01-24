/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:23:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/24 17:24:06 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# define WINDOW_W 	960
# define WINDOW_H	720

# define FOV			60
# define MINIMAP_SIZE	.5
# define PLAYER_SPEED	.1
# define PLAYER_SIZE	.1

# define COLOR_CEILING		0x8833CCFF
# define COLOR_FLOOR		0x88C99547
# define COLOR_WALL_N		0x88FF5733
# define COLOR_MAP_PLAYER	0x88FF0000
# define COLOR_MAP_FOV		0x88FF0000
# define COLOR_MAP_FLOOR	0x88FFFFFF
# define COLOR_MAP_WALL		0x88000000

# define LOOK_LEFT	65361
# define LOOK_RIGHT	65363
# define MOVE_FRWD	119
# define MOVE_BACK	115
# define MOVE_LEFT	97
# define MOVE_RIGHT	100
# define ESCAPE		65307

# define NORTH_ID "NO "
# define EAST_ID "EA "
# define SOUTH_ID "SO "
# define WEST_ID "WE "
# define FLOOR_ID "F "
# define CEILING_ID "C "

#define PI 3.14159265

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

//////////////////////////////-----STRUCTURES-----//////////////////////////////

typedef struct s_line
{
	int		start[2];
	int		end[2];
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		color;
}			t_line;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
}			t_image;

typedef struct s_xpm_color {
	char				c;
	char				*hex_code;
	struct s_xpm_color	*next;
}						t_xpm_color;

typedef struct s_xpm {
	char		*filepath;
	int			rows;
	int			columns;
	int			colors_count;
	int			bytes_per_pixel;
	t_xpm_color	*colors;
	char		**lines;
	int			fd;
}				t_xpm;

typedef struct s_ray_result {
	float	degree;
	float	distance;
	float	x;
	float	y;
	int		line_height;
	int		start_y;
	int		end_y;
	char	*texture_path;
	t_xpm	*xpm;
}			t_ray_result;

typedef struct s_env
{
	int		fd;
	char	*filepath;
	char	*line;

	char			**map;
	int				map_size[2];
	float			map_scale;

	int		fov_degrees;
	int		width_px;
	int		height_px;
	int		center_x;
	int		center_y;
	int		px_per_ray;
}			t_window;

typedef struct s_scene {
	struct s_window		*window;
	struct s_image		*image;

	struct s_ray_result	**rays;
	float				ray_resolution;
	struct s_xpm		**textures;

	char				**map;
	int					map_size[2];
	float				map_scale;
	struct s_line		*map_ray;

	float				player_position[2];
	int					player_orientation;
	int					player_direction[2];
	float				player_speed;
}			t_scene;

typedef struct s_env
{
	char			**map;
	int				map_size[2];
	float			map_scale;
	//struct s_line	*map_ray; //evtl. remove
	float			player_position[2];
	int				player_orientation;
	int				floor_hex;
	int				ceiling_hex;
	struct s_xpm	**wall_textures;
	//int		map_square_scale; remove?
}	t_env;

typedef struct s_parser
{
	int		fd;
	char	*filepath;
	char	*line;
	int		floor_colors[3];
	int		ceiling_colors[3];
	char	*north_text_path;
	char	*east_text_path;
	char	*south_text_path;
	char	*west_text_path;
	char	*map_string;
	char	**map_copy;
}	t_parser;

typedef struct s_data
{
	t_parser		*parser;
	t_env			*env;
	t_window		*window;
	t_ray_result	**rays;
}	t_data;


/////////////////////////////////-----MAIN-----/////////////////////////////////

int				main(int argc, char *argv[]);
void			check_args(int argc, char **argv);
void			exit_error(char *msg, t_data *data);

//////////////////////////////---INITIALIZATION---//////////////////////////////

t_data			*init_data(void);
t_ray_result	**init_rays(void);
t_env			*init_env(char **map);
t_window		*init_window(void);

t_xpm			*init_xpm(char *filename);
void			init_res(t_data *data);
int				*create_possible_moves_x(t_data *data);
int				*create_possible_moves_y(t_data *data);
char			**init_map(t_data *data);
void			init_env(t_data *data);


////////////////////////////////-----WINDOW-----////////////////////////////////

int		win_init(t_scene *scene);
int		win_destroy(t_scene *scene);

////////////////////////////////-----INPUT-----////////////////////////////////

void			event_hooks(t_data *data);

////////////////////////////////-----RENDER-----////////////////////////////////

void			render_frame(t_ray_result **rays, t_env *env);
void			render_rays(t_ray_result **rays, t_env *env);
int				cast_ray(t_ray_result *ray,  t_env *env, float angle);
void			render_player(t_env *env, int keycode);
void			render_player_position(t_env *env, int keycode);
void			render_player_orienation(t_env *env, int keycode);
void			set_direction(int dir[2], float angle);
void			find_next(float start[2], int dir[2]);
int				ray_collision(char **map, float dest[2], int dir[2]);
void			render_walls(t_ray_result **rays, t_env *env);
void			fix_fisheye(t_ray_result *rays[], int no_rays, int player_orientation);
int				map_scale(int map_size[2]);
void			assign_textures(t_ray_result *rays[], t_xpm **textures, int end);

/////////////////////////////////-----DRAW-----/////////////////////////////////

void			draw_frame(t_data *data);
void			draw_background(t_window *window, t_env *env);
void			draw_walls(t_data *data);
int				draw_map(t_data *data);
void			draw_floor(t_window *window, t_env *env);
int				draw_player(t_window *window, t_env *env);
int				draw_fov(t_window *window, t_ray_result **rays, t_env *env);
void			draw_line(t_window *window, int start[2], int end[2], int color);
void			draw_rectangle(t_window *window, int start[2], int end[2], int color);
int				get_pixel_color(t_ray_result ray, int y);
void			draw_pixel(t_window *window, int x, int y, int color);
void			draw_shader(t_window *window, int x, int y, float distance);

/////////////////////////////////-----MATH-----/////////////////////////////////

float			degr_to_rad(float degrees);
int				ft_abs(int num);
float			ft_absf(float num);
float			get_distance(float point_1[2], float point_2[2]);
int				is_whole_number(float num);
char			*get_hex_from_char(char c, t_xpm *xpm);
int				hex_digit_to_int(char ch);
int				hex_to_int(char *hex);

////////////////////////////////----PARSING----////////////////////////////////

t_xpm	*parse_xpm(char *filename);
void	print_xpm(t_xpm *xpm);

//////////////////////////////---INITIALIZATION---//////////////////////////////

t_scene	*scene_init(t_data *data);
char 	**map_init(void);
t_xpm	*init_xpm(char *filename);

///////////////////////////////-----INIT DATA-----//////////////////////////////

t_data			*init_data(void);
//void			init_res(t_data *data);
int				*create_possible_moves_x(t_data *data);
int				*create_possible_moves_y(t_data *data);
char			**init_map(t_data *data);


////////////////////////////////-----UTILS-----/////////////////////////////////

void			exit_error(char *msg, t_data *data);
//void			print_res(t_res *res);
void			print_string_array(char **array);
//void			print_map(t_map *map);

////////////////////////////////-----PARSE-----/////////////////////////////////

void			parse_file(t_data *data, char *filepath);
void			check_invalid_lines(t_data *data);

///////////////////////////-----PARSE TEXTURES-----/////////////////////////////

void			parse_textures(t_data *data);
void			save_identifier(char *identifier, char *line, t_data *data);
void			check_texture_file(char *path, t_data *data);
char			*remove_whitespace(char *src, t_data *data);

////////////////////////////-----PARSE COLORS-----//////////////////////////////

void			parse_colors(t_data *data);
void			save_color(char *identifier, char *line, t_data *data);
void			check_color_saved(t_data *data, char *identifier);
char			*save_next_hex(char *line, int *array, t_data *data);
int				valid_chars_color(char *str, t_data *data);
void			valid_number_format(char *str, t_data *data);
void			check_hex_range(t_data *data);
int				convert_to_hex(int rgb[3]);


////////////////////////////////-----FREE-----/////////////////////////////////

void			free_data(t_data *data);
void			free_parser(t_data *data);
void			free_env(t_data *data);
void			free_str_arr(char **arr);

/////////////////////////////-----PARSE MAP-----////////////////////////////////

void			parse_map(t_data *data);
int				is_valid_map_line(char *line);
void			calc_map_size(t_data *data);
void			calc_no_lines(t_data *data);
void			calc_line_length(t_data *data);
char			**create_map_arr(t_data *data, int i, int j, int k);
void			read_map(t_data *data);
void			get_player_pos(t_data *data);
void			get_player_orientation(t_data *data);

/////////////////////////////-----PARSE HELP-----///////////////////////////////

void			parse_successful(t_data *data);
int				only_spaces(char *line);


///////////////////////////////-----MAP_CHECK-----//////////////////////////////

void			check_map(t_data *data);
void			flood_fill(t_data *data, char **map, int x, int y);
int				is_valid_pos(char **map, int x, int y);
int				check_valid_chars(char **map, t_data *data);
int				is_valid_char(char c);

/////////////////////////////-----PARSE_XPM-----////////////////////////////////

void			parse_xpm_info(t_xpm *xpm, char *line);
void			add_new_color(t_xpm *xpm, char *line);
void			print_xpm(t_xpm *xpm);
t_xpm			*parse_xpm(char *filename);

////////////////////////////////-----FREE-----/////////////////////////////////

void			free_data(t_data *data);
void			free_env(t_env *env);
void			free_rays(t_ray_result **rays);
int				free_window(t_window *window);

void			free_res(t_data *data);
void			free_str_arr(char **arr);
void			free_map(char **map);

#endif