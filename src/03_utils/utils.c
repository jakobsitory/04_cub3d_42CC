/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:57:45 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/25 18:46:57 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	exit_error(char *msg, t_data *data)
{
	printf("Error\n");
	if (msg)
		printf("%s", msg);
	if (data)
		free_data(data);
	exit (1);
}

void	print_string_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		ft_printf("'%s'\n", array[i]);
		i++;
	}
	ft_printf("\n", array[i]);
}

void	print_rays(t_ray_result **rays)
{
	int	i;

	i = -1;
	while (++i < WINDOW_W)
	{
		printf("\npos\t[%f, %f]\ndegr\t%f\ndist\t%f\n' \
				'height\t%i [%i to %i]\ntxtr\t %s", \
		rays[i]->x, \
		rays[i]->y, \
		rays[i]->degree, \
		rays[i]->distance, \
		rays[i]->line_height, \
		rays[i]->start_y, \
		rays[i]->end_y, \
		rays[i]->xpm->filepath);
	}
}
