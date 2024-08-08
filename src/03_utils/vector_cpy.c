/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:40:14 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 12:58:47 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Copies the values from one 2D vector to another. This function takes two arrays of floats, `src` and `dest`, each representing a 2D vector,
 * and copies the `src` vector's values into the `dest` vector. It performs a check to ensure neither `src` nor `dest` is a null pointer before
 * proceeding with the copy operation.
 * 
 * @param dest The destination vector where values from `src` are copied to.
 * @param src The source vector from which values are copied.
 */
void	vector_cpy(float dest[2], float src[2])
{
	if (!dest || !src)
		return ;
	dest[0] = src[0];
	dest[1] = src[1];
}
