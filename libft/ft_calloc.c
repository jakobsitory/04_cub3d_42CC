/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:32:23 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:38:36 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates memory for an array of `nmemb` elements of `size` bytes each and returns a pointer
 * to the allocated memory. The memory is set to zero.
 * 
 * @param nmemb The number of elements to allocate.
 * @param size The size of each element in bytes.
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memloc;

	memloc = malloc (nmemb * size);
	if (!memloc)
		return (NULL);
	return (ft_memset(memloc, 0, nmemb * size));
}
