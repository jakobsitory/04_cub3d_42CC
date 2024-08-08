/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:12:18 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:17:25 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates and returns a substring from the string `s`.
 * 
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in `s`.
 * @param len The maximum length of the substring.
 * @return The newly created substring, or NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if ((long int) len < 0)
		len = ft_strlen(s);
	if ((long int) len + start >= ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *) malloc ((unsigned long int)len + 1);
	if (substr == NULL)
		return (NULL);
	if (!s || len <= 0 || start >= (unsigned int) ft_strlen(s))
	{
		free(substr);
		substr = ft_strdup("\0");
		return (substr);
	}
	while (s[start + i] != '\0' && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
