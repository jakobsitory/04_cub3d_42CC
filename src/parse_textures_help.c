/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:12:26 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/08 19:49:24 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	save_identifier(char *identifier, char *line, t_data *data)
{
	char *line_trimmed;

	line += ft_strlen(identifier);
	line_trimmed = ft_strtrim(line, " \n");
	check_texture_file(line, data);
	if (ft_strncmp(identifier, NORTH_ID, ft_strlen(identifier)) == 0)
		data->res->north_text_path = ft_strdup(line_trimmed);
	else if (ft_strncmp(identifier, EAST_ID, ft_strlen(identifier)) == 0)
		data->res->east_text_path = ft_strdup(line_trimmed);
	else if (ft_strncmp(identifier, SOUTH_ID, ft_strlen(identifier)) == 0)
		data->res->south_text_path = ft_strdup(line_trimmed);
	else if (ft_strncmp(identifier, WEST_ID, ft_strlen(identifier)) == 0)
		data->res->west_text_path = ft_strdup(line_trimmed);
	free(line_trimmed);
}

void	check_texture_file(char *path, t_data *data)
{
	int		fd;

	path = ft_strtrim(path, " \n");
	fd = open(path, O_RDONLY);
	if (fd < 1)
		exit_error(TEXTURE_ERR, data);
	close(fd);
	free(path);
}

char	*remove_whitespace(char *src, t_data *data)
{
	int		i;
	int		j;
	int		count;
	char	*res;

	i = 0;
	count = 0;
	while (src[i])
	{
		if (src[i] == ' ')
			count++;
		i++;
	}
	res = malloc(sizeof(char) * (ft_strlen(src) - count) + 1);
	if (!res)
		exit_error(MALLOC_ERR, data);
	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] != ' ')
			res[j++] = src[i];
		i++;
	}
	res[j] = '\0';
	return (res);
}
