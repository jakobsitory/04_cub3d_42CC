/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:20:43 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:26:18 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Fills the first `n` bytes of the memory area pointed to by `s` with the constant byte `c`.
 * 
 * @param s Pointer to the memory area to be filled.
 * @param c The byte value to fill the memory area with, passed as an `int`.
 * @param n The number of bytes to fill.
 * @return The original pointer `s` to the memory area.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
