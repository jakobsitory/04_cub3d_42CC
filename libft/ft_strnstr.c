/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:33:43 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:19:39 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Locates a substring in a string, searching up to a maximum length.
 * 
 * @param big The string to search in.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search.
 * @return A pointer to the beginning of the located substring, or NULL if the substring is not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	char	*pos;

	if (little[0] == '\0' || big == little)
		return ((char *) big);
	i = 0;
	if (!ft_strchr(big, little[0]))
		return (NULL);
	pos = ft_strchr(big, little[0]);
	i = pos - big + i;
	while ((i + (size_t) ft_strlen(little) <= len))
	{
		if (!ft_strncmp(pos, (char *) little, ft_strlen(little)))
		{
			return (pos);
		}
		pos = ft_strchr(&big[i + 1], little[0]);
		i = pos - big;
	}
	return (NULL);
}
