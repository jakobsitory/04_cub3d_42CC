/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   draw_lines.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jschott <jschott@student.42berlin.de>	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/08/28 12:04:56 by jschott		   #+#	#+#			 */
/*   Updated: 2023/09/20 17:12:52 by jschott		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/j_cub3D.h"

void	draw_bresenham(t_image *img, t_line *line)
{
	while (1)
	{
		my_mlx_pixel_put(img, line->start[0], line->start[1], line->color);
		if (line->start[0] == line->end[0] && line->start[1] == line->end[1])
			break ;
		line->e2 = 2 * line->err;
		if (line->e2 > -line->dy)
		{
			line->err -= line->dy;
			line->start[0] += line->sx;
		}
		if (line->e2 < line->dx)
		{
			line->err += line->dx;
			line->start[1] += line->sy;
		}
	}
}

void	draw_line(t_image *img, int start[2], int end[2], int color)
{
	t_line	*line;

	line = (t_line *) malloc (sizeof(t_line));
	if (!line)
		return ;
	line->start[0] = start[0];
	line->start[1] = start[1];
	line->end[0] = end[0];
	line->end[1] = end[1];
	line->dx = ft_abs(line->end[0] - line->start[0]);
	line->dy = ft_abs(line->end[1] - line->start[1]);
	line->err = line->dx - line->dy;
	line->e2 = 2 * line->err;
	line->color = color;
	if (start[0] < line->end[0])
		line->sx = 1;
	else
		line->sx = -1;
	if (start[1] < line->end[1])
		line->sy = 1;
	else
		line->sy = -1;
	draw_bresenham(img, line);
	free(line);
}
