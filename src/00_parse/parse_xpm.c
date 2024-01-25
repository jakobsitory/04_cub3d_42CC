/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:20:41 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/25 19:02:07 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_xpm_info(t_xpm *xpm, char *line)
{
	char	*tr_line;
	char	**split;

	tr_line = ft_substr(line, 1, ft_strlen(line) - 4);
	split = ft_split(tr_line, ' ');
	xpm->rows = ft_atoi(split[0]);
	xpm->columns = ft_atoi(split[1]);
	xpm->colors_count = ft_atoi(split[2]);
	xpm->bytes_per_pixel = ft_atoi(split[3]);
	free_str_arr(split);
	free(tr_line);
}

void	add_new_color(t_xpm *xpm, char *line, t_data *data)
{
	t_xpm_color	*color;
	t_xpm_color	*tmp;

	color = malloc(sizeof(t_xpm_color));
	if (!color)
		exit_error(MALLOC_ERR, data);
	color->c = line[1];
	color->hex_code = ft_substr(line, 5, ft_strlen(line) - 8);
	color->next = NULL;
	if (xpm->colors == NULL)
		xpm->colors = color;
	else
	{
		tmp = xpm->colors;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = color;
	}
}

void	get_next_line_wrapper(char **line, int *line_no, int fd)
{
	free(*line);
	*line = get_next_line(fd);
	(*line_no)++;
}

void	parse_xpm_lines(t_xpm *xpm, char **line, int *line_no, t_data *data)
{
	int	i;

	i = 0;
	xpm->lines = malloc(sizeof(char *) * (xpm->rows + 1));
	if (!xpm->lines)
		exit_error(MALLOC_ERR, data);
	while (i < xpm->rows)
	{
		xpm->lines[i] = ft_substr(*line, 1, ft_strlen(*line) - 4);
		get_next_line_wrapper(line, line_no, xpm->fd);
		i++;
	}
	xpm->lines[i] = NULL;
}

t_xpm	*parse_xpm(char *filename, t_data *data)
{
	char	*line;
	int		line_no;
	t_xpm	*xpm;

	if (!filename)
		return (0);
	xpm = init_xpm(filename, data);
	line_no = 0;
	line = get_next_line(xpm->fd);
	while (line_no < 2)
		get_next_line_wrapper(&line, &line_no, xpm->fd);
	if (line_no == 2)
		parse_xpm_info(xpm, line);
	get_next_line_wrapper(&line, &line_no, xpm->fd);
	while (line_no <= xpm->colors_count + 2)
	{
		add_new_color(xpm, line, data);
		get_next_line_wrapper(&line, &line_no, xpm->fd);
	}
	parse_xpm_lines(xpm, &line, &line_no, data);
	return (xpm);
}
