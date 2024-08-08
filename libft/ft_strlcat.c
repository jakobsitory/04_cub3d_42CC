/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:21:48 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:21:36 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Appends the string `src` to the end of `dest`, but takes the full size of the destination buffer
 * and guarantees NUL-termination if there is room. Note that room for the NUL should be included in `size`.
 * 
 * @param dest The destination string to which `src` is appended.
 * @param src The source string to append to `dest`.
 * @param size The size of the destination buffer (including space for the null terminator).
 * @return The total length of the string it tried to create, which is the initial length of `dest`
 *         plus the length of `src`. If the return value is >= `size`, the output string has been truncated.
 */
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			l_dest;
	size_t			l_src;

	l_dest = ft_strlen (dest);
	l_src = ft_strlen (src);
	j = 0;
	i = l_dest;
	if (size == 0 || size <= l_dest)
		return (size + l_src);
	while (src[j] != '\0' && j < size - l_dest - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (l_dest + l_src);
}
