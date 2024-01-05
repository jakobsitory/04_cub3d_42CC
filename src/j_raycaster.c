/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   j_raycaster.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jschott <jschott@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/04 17:30:29 by jschott		   #+#	#+#			 */
/*   Updated: 2024/01/04 17:47:06 by jschott		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/j_header.h"

char **init_map(void)
{
	int i, j;
	char **map = malloc(8 * sizeof(char *));

	if (map == NULL)
		return (NULL);

	for (i = 0; i < 8; i++)
	{
		map[i] = malloc(8 * sizeof(char));
		if (map[i] == NULL)
			return (NULL);
	}

	char temp[8][8] = {
		{1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1}
	};

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
			map[i][j] = temp[i][j];
	}

	return map;
}

int	main(void)
{
	char **map;

	map = init_map();
	return (0);
}
