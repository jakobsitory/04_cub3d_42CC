/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:50:36 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:18:17 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Trims characters from both ends of a string.
 * 
 * @param s1 The string to be trimmed.
 * @param set The set of characters to trim from `s1`.
 * @return A newly allocated string with the trimmed content, or NULL on allocation failure.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trimmed;

	start = 0;
	end = ft_strlen(s1);
	while (start != end && ft_strchr ((set), s1[start]))
		start++;
	while (start < end && ft_strchr ((set), s1[end - 1]))
		end--;
	if (start == end || !s1 || !set)
	{
		trimmed = (char *) malloc (1);
		if (trimmed == NULL)
			return (NULL);
		trimmed[0] = '\0';
		return (trimmed);
	}
	trimmed = (char *) malloc ((end - start) + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_strlcpy(trimmed, &s1[start], end - start + 1);
	return (trimmed);
}
