/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:23:03 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:20:05 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Compares two strings up to a specified number of characters.
 * 
 * If `n` is 0, the function returns 0 immediately, indicating no comparison was made.
 * 
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @param n The maximum number of characters to compare.
 * @return The difference between the first differing characters in `s1` and `s2`,
 *         or 0 if the strings are identical up to `n` characters.
 */
int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
