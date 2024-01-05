/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:22:00 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/05 12:54:54 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_cub3D.h"
#include "cub3D.h"


int	main(int argc, char *argv[])
{
	t_data	*data;

	data = NULL;
	check_args(argc, argv);
	printf("check_args succesfull\n");
	parse_file(data);
	return (0);
}

void	check_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		exit_error(USAGE_ERR);
	if (ft_strlen(argv[1]) <= 5)
		exit_error(USAGE_ERR);
	if (!(ft_strncmp(".cub", argv[1] + (ft_strlen(argv[1]) - 4), 4) == 0))
		exit_error(USAGE_ERR);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error(FILE_ERR);
	close(fd);
}
