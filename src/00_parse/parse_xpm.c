/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:20:41 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/01/23 17:23:02 by jschott          ###   ########.fr       */
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
	free(tr_line);
}

void	add_new_color(t_xpm *xpm, char *line)
{
	t_xpm_color	*color;
	t_xpm_color	*tmp;

	color = malloc(sizeof(t_xpm_color));
	if (!color)
		return ;
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

void	print_xpm(t_xpm *xpm)
{
	t_xpm_color	*tmp_color;
	int			i;

	printf("---GENERAL:---\n%i, %i, %i, %i\n", xpm->rows, xpm->columns, \
				xpm->colors_count, xpm->bytes_per_pixel);
	tmp_color = xpm->colors;
	printf("---COLORS---\n");
	while (tmp_color)
	{
		printf("%c->%s\n", tmp_color->c, tmp_color->hex_code);
		tmp_color = tmp_color->next;
	}
	printf("---IMAGE:---\n");
	i = -1;
	while (++i < xpm->rows)
		printf("%s\n", xpm->lines[i]);
	printf("---END---\n");
}

void	get_next_line_wrapper(char **line, int *line_no, int fd)
{
	free(*line);
	*line = get_next_line(fd);
	(*line_no)++;
}

t_xpm	*init_xpm(char *filename)
{
	t_xpm	*xpm;

	xpm = malloc(sizeof(t_xpm));
	if (!xpm)
		return (NULL);
	xpm->colors = malloc(sizeof(t_xpm_color));
	if (!xpm->colors)
		return (NULL);
	xpm->colors = NULL;
	xpm->fd = open(filename, O_RDONLY);
	if (xpm->fd < 0)
	{
		printf("could not open xpm: %s\n", filename);
		exit (0); //CLEAN EXIT TBD
	}
	return (xpm);
}

void	parse_xpm_lines(t_xpm *xpm, char **line, int *line_no)
{
	int	i;

	i = 0;
	xpm->lines = malloc(sizeof(char *) * (xpm->rows + 1));
	if (!xpm->lines)
		return ;
	while (i < xpm->rows)
	{
		xpm->lines[i] = ft_substr(*line, 1, ft_strlen(*line) - 4);
		get_next_line_wrapper(line, line_no, xpm->fd);
		i++;
	}
	xpm->lines[i] = NULL;
}

t_xpm	*parse_xpm(char *filename)
{
	char	*line;
	int		line_no;
	t_xpm	*xpm;

	xpm = init_xpm(filename);
	line_no = 0;
	line = get_next_line(xpm->fd);
	while (line_no < 2)
		get_next_line_wrapper(&line, &line_no, xpm->fd);
	if (line_no == 2)
		parse_xpm_info(xpm, line);
	get_next_line_wrapper(&line, &line_no, xpm->fd);
	while (line_no <= xpm->colors_count + 2)
	{
		add_new_color(xpm, line);
		get_next_line_wrapper(&line, &line_no, xpm->fd);
	}
	parse_xpm_lines(xpm, &line, &line_no);
	return (xpm);
}
