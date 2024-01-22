/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:23:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/22 11:11:52 by lgrimmei         ###   ########.fr       */
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
# include <mlx.h>
# include <math.h>


//////////////////////////////-----STRUCTURES-----//////////////////////////////

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

typedef struct s_xpm_color {
	char				c;
	char				*hex_code;
	struct s_xpm_color	*next;
}	t_xpm_color;

typedef struct s_xpm {
	int			rows;
	int			columns;
	int			colors_count;
	int			bytes_per_pixel;
	t_xpm_color	*colors;
	char		**lines;
	int			fd;
}	t_xpm;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		width;
	int		height;
	int		endian;
}			t_image;

typedef struct s_ray_result {
	int		degree;
	float	distance;
	float	x;
	float	y;
	int		line_height;
	int		start_y;
	int		end_y;
	char	*texture_path;
	t_xpm	*xpm;
}	t_ray_result;

typedef struct s_window {
	int		fov_degrees;
	int		width_px;
	int		height_px;
	int		center_x;
	int		center_y;
	int		px_per_ray;
}	t_window;

/////////////////////////////////-----MAIN-----/////////////////////////////////

int				main(void);
void			check_args(int argc, char **argv);








////////////////////////////////-----DEFINES-----///////////////////////////////


#endif