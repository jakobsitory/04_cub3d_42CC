/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_cub3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:23:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/08 17:19:07 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef J_CUB3D_H
# define J_CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

# define WINDOW_W 	1024
# define WINDOW_H	768

# define COLOR_CEILING 0x0033CCFF
# define COLOR_FLOOR 0x00C99547
# define COLOR_WALL_N 0x00FF5733
# define COLOR_MAP_PLAYER 0xFF0000
# define COLOR_MAP_FLOOR 0xFFFFFF
# define COLOR_MAP_WALL 0x000000


# define LOOK_LEFT 65361
# define LOOK_RIGHT 65363
# define MOVE_FRWD 119
# define MOVE_BACK 115
# define MOVE_LEFT 97
# define MOVE_RIGHT 100
# define ESCAPE 65307

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

typedef struct s_window {
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
}			t_window;

typedef struct s_scene {
	struct s_window	*window;
	struct s_image	*image;

	char			**map;
	int				map_size[2];
	int				map_square_scale;

	int				player_position[2];
	int				player_orientation;
}			t_scene;

/////////////////////////////////-----MAIN-----/////////////////////////////////

// int	main(int argc, char *argv[]);
int		main(void);

////////////////////////////////-----WINDOW-----////////////////////////////////

int		win_init(t_scene *scene);
int		win_destroy(t_scene *scene);

////////////////////////////////-----INPUT-----////////////////////////////////

void	key_events(t_scene *scene);

/////////////////////////////////-----DRAW-----/////////////////////////////////

void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	background_fill(t_scene *scene);
void	rectangle_fill(t_image *image, int start[2], int end[2], int color);
int		draw_map(t_scene *scene);
void	draw_line(t_image *img, int start[2], int end[2], int color);
int		cast_ray(t_scene *scene, int angle);
int		map_scale(int map_size[2]);

/////////////////////////////////-----MATH-----/////////////////////////////////

float	degr_to_rad(int degrees);
int		ft_abs(int num);

///////////////////////////////-----MAP_CHECK-----//////////////////////////////

#endif
