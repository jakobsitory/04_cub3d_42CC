/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_cub3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:23:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/05 12:42:18 by jschott          ###   ########.fr       */
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

# define WIN_WIDTH 	1024
# define WIN_HEIGHT	768

# define COLOR_CEILING 0x0033CCFF
# define COLOR_FLOOR 0x004A5B6D
# define COLOR_WALL_N 0x00FF5733

# define LOOK_LEFT 65361
# define LOOK_RIGHT 65363
# define MOVE_FRWD 119
# define MOVE_BACK 115
# define MOVE_LEFT 97
# define MOVE_RIGHT 100
# define ESCAPE 65307

//////////////////////////////-----STRUCTURES-----//////////////////////////////

typedef struct s_image {
	void	*img;
	// void	*next_image;
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
}			t_scene;

/////////////////////////////////-----MAIN-----/////////////////////////////////

// int	main(int argc, char *argv[]);
int	main(void);

////////////////////////////////-----WINDOW-----////////////////////////////////

int		win_init(t_scene *scene);
int		win_destroy(t_scene *scene);

////////////////////////////////-----INPUT-----////////////////////////////////

void	key_events(t_scene *scene);

/////////////////////////////////-----DRAW-----/////////////////////////////////

void	background_fill(t_scene *scene);

///////////////////////////////-----MAP_CHECK-----//////////////////////////////

#endif
