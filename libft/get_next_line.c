/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:30:25 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/21 13:41:58 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_no_newline(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		return (1);
	}
	while (s[i])
	{
		if (s[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

int	clean_res_get_start(char *res)
{
	int	start;

	start = 0;
	while (res[start])
	{
		if (res[start] == '\n')
		{
			start++;
			break ;
		}
		start++;
	}
	return (start);
}

char	*clean_res(char *res, int bread)
{
	char	*new;
	int		i;
	int		start;

	if (bread == -1)
		return (free(res), NULL);
	i = 0;
	if (!res)
		return (NULL);
	start = clean_res_get_start(res);
	if (!res[start])
		return (free(res), NULL);
	new = malloc(((int)ft_strlen_gnl(res) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < (int)ft_strlen_gnl(res) - start)
	{
		new[i] = res[i + start];
		i++;
	}
	new[i] = '\0';
	return (free(res), new);
}

char	*get_full_line(char *res, int bread)
{
	char	*line;
	int		i;
	int		len;

	if (bread == -1)
		return (NULL);
	i = 0;
	len = 0;
	if (!res)
		return (NULL);
	while (res[len])
	{
		len++;
		if (res[len - 1] == '\n')
			break ;
	}
	line = ft_calloc_gnl(len + 1, 1);
	while (i < len)
	{
		line[i] = res[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*res;
	int			bread;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bread = 1;
	while (ft_no_newline(res) == 1)
	{
		buffer = ft_calloc_gnl((BUFFER_SIZE + 1) * sizeof(char), 1);
		if (!buffer)
			return (NULL);
		bread = read(fd, buffer, BUFFER_SIZE);
		if (bread <= 0)
		{
			free (buffer);
			break ;
		}
		res = ft_strjoin_gnl(res, buffer);
		free(buffer);
	}
	line = get_full_line(res, bread);
	res = clean_res(res, bread);
	return (line);
}
