/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:10:54 by jschott           #+#    #+#             */
/*   Updated: 2024/01/24 15:20:04 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void free_data(t_data *data)
{
	if (data->env)
		free_env(data->env);
	if (data->rays)
		free_rays(data->rays);
	if (data->window)
		free_window(data->window);
}