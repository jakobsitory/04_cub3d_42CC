/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:21:11 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:26:46 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies `n` bytes from memory area `src` to memory area `dest`.
 * 
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return A pointer to the destination memory area `dest`.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int			i;
	char		*cdest;
	const char	*csrc;

	cdest = (char *) dest;
	csrc = (const char *) src;
	i = 0;
	if (!src && !dest)
		return (dest);
	while (i < (int) n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return ((void *) cdest);
}
