/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:33:18 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:28:52 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for the first occurrence of a character in a memory area.
 * 
 * @param s Pointer to the memory area to be searched.
 * @param c The character to search for, represented as an int but treated as an unsigned char.
 * @param n The number of bytes to be scanned.
 * @return A pointer to the matching byte in the memory area, or NULL if `c` is not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	int					i;
	const unsigned char	*ptr;

	i = 0;
	ptr = s;
	while (i < (int)n)
	{
		if (ptr[i] == (unsigned char) c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
