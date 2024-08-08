/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:02:41 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:22:05 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <string.h>

/**
 * Concatenates two strings into a new string.
 * 
 * @param s1 The first string to concatenate.
 * @param s2 The second string to concatenate.
 * @return The concatenated string, or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*joinstr;
	long int	joinlen;

	joinlen = (ft_strlen(s1) + ft_strlen(s2));
	joinstr = (char *) malloc (joinlen + 1);
	if (joinstr == NULL)
		return (NULL);
	ft_strlcpy(joinstr, s1, joinlen + 1);
	ft_strlcat(joinstr, s2, joinlen + 1);
	return (joinstr);
}
