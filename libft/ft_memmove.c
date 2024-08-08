/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:21:25 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:26:33 by jschott          ###   ########.fr       */
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
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	char		*cdest;
	const char	*csrc;

	i = 0;
	cdest = (char *) dest;
	csrc = (const char *) src;
	if (cdest <= csrc && (src || dest))
	{
		while (i < (int) n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	else if (src || dest)
	{
		while (n > 0)
		{
			cdest[n - 1] = csrc[n - 1];
			n--;
		}
	}
	return (dest);
}
