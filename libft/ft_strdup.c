/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 08:32:54 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:22:38 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Duplicates a string.
 * 
 * @param s The string to duplicate.
 * @return A pointer to the newly allocated string, or NULL if the allocation fails.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *) malloc (ft_strlen (s) + 1);
	if (!dup)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = (char) s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
