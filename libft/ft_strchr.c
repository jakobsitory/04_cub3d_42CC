/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:22:52 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:22:53 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locates the first occurrence of a character in a string.
 * 
 * @param s The string to search.
 * @param c The character to search for, represented as an int.
 * @return A pointer to the first occurrence of `c` in `s`, or NULL if `c` is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{	
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if ((char) c == '\0')
		return ((char *) &s[i]);
	return (NULL);
}
