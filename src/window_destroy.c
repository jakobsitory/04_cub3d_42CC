/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:08:22 by jschott           #+#    #+#             */
/*   Updated: 2024/01/05 11:59:26 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/j_cub3D.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"

int	win_destroy(t_scene *scene)
{
	mlx_destroy_image(scene->window->mlx, scene->image->img);
	mlx_destroy_window(scene->window->mlx, scene->window->mlx_win);
	mlx_destroy_display(scene->window->mlx);
	free (scene->window->mlx);
	free (scene->window);
	free (scene->image);
	free (scene);
	return (0);
}

