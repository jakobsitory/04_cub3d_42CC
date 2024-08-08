/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:21:39 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:21:11 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies a string into another, ensuring the target is null-terminated.
 * 
 * @param dest The buffer where the string is copied to.
 * @param src The source string to copy from.
 * @param size The size of the destination buffer.
 * @return The total length of the string it tried to create, meaning the length of `src`.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = ft_strlen (src);
	i = 0;
	if ((int) size != 0)
	{
		while (src [i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (j);
}
