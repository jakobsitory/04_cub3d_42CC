/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <leon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:29:31 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/05 15:10:04 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((int)(nmemb * size));
	if (!ptr)
		return (NULL);
	while (i < (int)(nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin_helper(char const *s1, char const *s2, char *res)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[i + ft_strlen_gnl(s1)] = s2[i];
		i++;
	}
	res[i + ft_strlen_gnl(s1)] = '\0';
	return (res);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;

	if (!s1)
		s1 = ft_strdup_gnl("");
	res = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (!res)
	{
		free((void *)s1);
		return (NULL);
	}
	res = ft_strjoin_helper(s1, s2, res);
	free ((void *)s1);
	return (res);
}

size_t	ft_strlen_gnl(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s)
{
	int		len;
	char	*dest;
	int		i;

	i = 0;
	len = ft_strlen_gnl(s);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
	{
		free(dest);
		return (NULL);
	}
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
