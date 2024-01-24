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

#include "cub3D.h"

/**
 * Draws a line using the Bresenham's line algorithm.
 *
 * @param img The image to draw the line on.
 * @param line The line to be drawn.
 */
void	draw_bresenham(t_window *window, t_line *line)
{
	while (1)
	{
		draw_pixel(window, line->start[0], line->start[1], line->color);
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

/**
 * Draws a line on the given image using Bresenham's line algorithm.
 *
 * @param img The image to draw the line on.
 * @param start The starting coordinates of the line.
 * @param end The ending coordinates of the line.
 * @param color The color of the line.
 */
void	draw_line(t_window *window, int start[2], int end[2], int color)
{
	t_line	*line;

	line = window->line_buffer;
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
	draw_bresenham(window, line);
}
