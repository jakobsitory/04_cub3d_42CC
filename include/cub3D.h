/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:23:15 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/04 19:24:08 by lgrimmei         ###   ########.fr       */
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

void	exit_error(char *msg);

////////////////////////////////-----PARSE-----/////////////////////////////////

void	parse_file(t_data *data);

///////////////////////////////-----MAP_CHECK-----//////////////////////////////

////////////////////////////////-----DEFINES-----///////////////////////////////

# define USAGE_ERR "Correct Usage: [./cub3d xxx.cub]\n"
# define FILE_ERR "Unable to locate or read file\n"

#endif