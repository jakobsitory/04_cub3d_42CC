/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:23:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/08 20:04:52 by lgrimmei         ###   ########.fr       */
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
}	t_res;

typedef struct data
{
	int		fd;
	char	*filepath;
	t_res	*res;
}	t_data;

/////////////////////////////////-----MAIN-----/////////////////////////////////

int		main(int argc, char *argv[]);
void	check_args(int argc, char **argv);

////////////////////////////////-----UTILS-----/////////////////////////////////

void	exit_error(char *msg, t_data *data);
void	print_res(t_res *res);
void	free_data(t_data *data);

////////////////////////////////-----PARSE-----/////////////////////////////////

void	parse_file(t_data *data, char *filepath);
void	parse_textures(t_data *data);
void	save_identifier(char *identifier, char *line, t_data *data);
void	check_texture_file(char *path, t_data *data);
char	*remove_whitespace(char *src, t_data *data);
void	parse_colors(t_data *data);
void	save_color(char *identifier, char *line, t_data *data);
char	*save_next_hex(char *line, int *array, t_data *data);
int		valid_chars_color(char *str, t_data *data);
void	valid_number_format(char *str, t_data *data);
void	check_hex_range(t_data *data);


///////////////////////////////-----MAP_CHECK-----//////////////////////////////

////////////////////////////////-----DEFINES-----///////////////////////////////

# define USAGE_ERR "Correct Usage: [./cub3d xxx.cub]\n"
# define FILE_ERR "Unable to locate or read file\n"
# define TEXTURE_ERR "Unable to locate or read texture file\n"
# define COLOR_ERR "Invalid Color Definition\n"
# define MALLOC_ERR "Failed to allocate memory\n"


# define NORTH_ID "NO "
# define EAST_ID "EA "
# define SOUTH_ID "SO "
# define WEST_ID "WE "
# define FLOOR_ID "F "
# define CEILING_ID "C "


#endif