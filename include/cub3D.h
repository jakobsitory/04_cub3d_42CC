/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:23:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/23 17:29:01 by lgrimmei         ###   ########.fr       */
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

# define FOV			90
# define MINIMAP_SIZE	.25

# define COLOR_CEILING		0x0033CCFF
# define COLOR_FLOOR		0x00C99547
# define COLOR_WALL_N		0x00FF5733
# define COLOR_MAP_PLAYER	0x00FF0000
# define COLOR_MAP_FOV		0x00FF0000
# define COLOR_MAP_FLOOR	0x00FFFFFF
# define COLOR_MAP_WALL		0x00000000

#define NORTH_TEXTURE "resources/wall.xpm"
#define EAST_TEXTURE "resources/wall.xpm"
#define SOUTH_TEXTURE "resources/wall.xpm"
#define WEST_TEXTURE "resources/wall.xpm"

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

typedef struct s_window {
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;

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

typedef struct s_res
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

typedef struct s_map
{
	char	*map_string;
	int		map_size[2];
	int		map_square_scale;
	char	**map;
	char	**map_copy;
	int		player_position[2];
	int		player_orientation;
	int		*x_moves;
	int		*y_moves;
}	t_map;

typedef struct s_data
{
	int		fd;
	char	*filepath;
	t_res	*res;
	char	*line;
	t_map	*map;
}	t_data;

/////////////////////////////////-----MAIN-----/////////////////////////////////

int				main(int argc, char *argv[]);
void			check_args(int argc, char **argv);

///////////////////////////////-----INIT DATA-----//////////////////////////////

t_data			*init_data(void);
void			init_res(t_data *data);
int				*create_possible_moves_x(t_data *data);
int				*create_possible_moves_y(t_data *data);
char			**init_map(t_data *data);

////////////////////////////////-----WINDOW-----////////////////////////////////

int		win_init(t_scene *scene);
int		win_destroy(t_scene *scene);

////////////////////////////////-----INPUT-----////////////////////////////////

void	key_events(t_scene *scene);

/////////////////////////////////-----DRAW-----/////////////////////////////////

void	draw_walls(t_scene *scene);
void	background_fill(t_scene *scene);
int		draw_map(t_scene *scene);
int		draw_fov(t_scene *scene);
void	rectangle_fill(t_image *image, int start[2], int end[2], int color);
void	draw_line(t_scene *scene, int start[2], int end[2]);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);

////////////////////////////////---CALC--RAYS---////////////////////////////////

void	cast_all_rays(t_scene *scene);
int		cast_ray(t_ray_result *ray,  t_scene *scene, float angle);
void	find_next(float start[2], int dir[2]);
void	write_to_ray_results(t_ray_result *rays, int square[2], float distance, int i);
int		map_scale(int map_size[2]);
void	get_texture(t_ray_result *ray);
void	prepare_rays(t_scene *scene);
void	set_direction(int dir[2], float angle);

/////////////////////////////////-----MATH-----/////////////////////////////////

float	degr_to_rad(float degrees);
int		ft_abs(int num);
float	get_distance(float point_1[2], float point_2[2]);
float	ft_absf(float num);
int		is_whole_number(float num);
char	*get_hex_from_char(char c, t_xpm *xpm);
int		hex_digit_to_int(char ch);
int		hex_to_int(char *hex);

/////////////////////////////////----PARSING----////////////////////////////////

t_xpm	*parse_xpm(char *filename);
void	print_xpm(t_xpm *xpm);

//////////////////////////////---INITIALIZATION---//////////////////////////////

t_scene	*scene_init(t_data *data);
char 	**map_init(void);
t_xpm	*init_xpm(char *filename);

///////////////////////////////-----INIT DATA-----//////////////////////////////

t_data			*init_data(void);
void			init_res(t_data *data);
int				*create_possible_moves_x(t_data *data);
int				*create_possible_moves_y(t_data *data);
char			**init_map(t_data *data);


////////////////////////////////-----UTILS-----/////////////////////////////////

void			exit_error(char *msg, t_data *data);
void			print_res(t_res *res);
void			print_string_array(char **array);
void			print_map(t_map *map);

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
void			free_res(t_data *data);
void			free_str_arr(char **arr);
void			free_map(t_data *data);

/////////////////////////////-----PARSE MAP-----////////////////////////////////

void			parse_map(t_data *data);
int				is_valid_map_line(char *line);
void			calc_map_size(t_map *map);
void			calc_no_lines(t_map *map);
void			calc_line_length(t_map *map);
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

/////////////////////////////-----RENDER_MAP-----///////////////////////////////

t_window		*init_window(void);
t_ray_result	*init_rays();

int				get_pixel_color(t_ray_result ray, int y);
void			display_image(void *mlx, void *win, t_ray_result *rays, t_window *window);
void			get_texture(t_ray_result *ray);
void			assign_textures(t_ray_result *rays[], t_xpm **textures ,int no_rays, int i);
//void			fix_fisheye(t_ray_result *rays[], int no_rays, int player_orientation);
//t_ray_result	*prepare_rays(t_ray_result rays[], t_window *window);

#endif