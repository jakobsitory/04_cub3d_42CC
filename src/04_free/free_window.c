/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:08:22 by jschott           #+#    #+#             */
/*   Updated: 2024/01/25 18:47:10 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	free_window(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img);
	mlx_destroy_window(window->mlx, window->mlx_win);
	mlx_destroy_display(window->mlx);
	free (window->line_buffer);
	free (window->mlx);
	free (window);
	return (0);
}
