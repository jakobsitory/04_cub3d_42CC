/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:12:00 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:18:49 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for the last occurrence of a character in a string.
 * 
 * @param s The string to search.
 * @param c The character to search for, represented as an int.
 * @return A pointer to the last occurrence of `c` in `s`, or NULL if `c` is not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{	
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
