/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:57:38 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/08/08 12:50:13 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Initiates the map validation process for the cub3D project. It first checks if the map contains only valid characters and then
 * applies a flood fill algorithm starting from the player's position to ensure all accessible areas are properly enclosed.
 * 
 * @param data Pointer to the game's data structure, containing the environment and parser information.
 */
void	check_map(t_data *data)
{
	if (!check_valid_chars(data->env->map, data))
		exit_error(CHARS_ERR, data);
	flood_fill(data, data->parser->map_copy, data->env->player_position[0] \
	, data->env->player_position[1]);
}
void check_map(t_data *data);

/**
 * Recursively applies a flood fill algorithm to mark accessible areas of the map. It checks for walls ('1') and already visited
 * spaces ('X') to prevent infinite recursion. The function also validates the map boundaries and ensures the player cannot move
 * outside the map.
 * 
 * @param data Pointer to the game's data structure, containing the environment and parser information.
 * @param map A copy of the game map where the flood fill algorithm is applied.
 * @param x The current x-coordinate in the map being checked.
 * @param y The current y-coordinate in the map being checked.
 */
void	flood_fill(t_data *data, char **map, int x, int y)
{
	int	i;

	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	i = 0;
	if (x >= data->env->map_size[0] - 1 || \
	y >= data->env->map_size[1] - 1 || !is_valid_pos(map, x, y))
		exit_error(MAP_ERR, data);
	map[y][x] = 'X';
	while (i < 8)
	{
		flood_fill(data, map, x + data->parser->x_moves[i], y + data->parser->y_moves[i]);
		i++;
	}
}

/**
 * Checks if a given position on the map is considered valid for the player to stand on. Valid positions include '0' (empty space)
 * and 'N', 'E', 'S', 'W' (indicating player start position and direction).
 * 
 * @param map The game map.
 * @param x The x-coordinate of the position to check.
 * @param y The y-coordinate of the position to check.
 * @return 1 if the position is valid, 0 otherwise.
 */
int	is_valid_pos(char **map, int x, int y)
{
	if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'E' \
	|| map[y][x] == 'S' || map[y][x] == 'W')
		return (1);
	return (0);
}

/**
 * Scans the entire map for any characters that are not allowed. This function ensures the map contains only valid symbols before
 * starting the game. The specific characters checked and the action taken on finding an invalid character are not detailed in the
 * excerpt provided.
 * 
 * @param map The game map.
 * @param data Pointer to the game's data structure, potentially used for additional validation or error handling.
 * @return Implementation-specific return value, not detailed in the excerpt provided.
 */
int	check_valid_chars(char **map, t_data *data)
{
	int	x;
	int	y;
	int	flag;

	x = 0;
	y = 0;
	flag = 0;
	while (y < data->env->map_size[1])
	{
		while (x < data->env->map_size[0])
		{
			if (!is_valid_char(map[y][x]))
				return (0);
			if (map[y][x] == 'N' || map[y][x] == 'E' \
			|| map[y][x] == 'S' || map[y][x] == 'W')
				flag++;
			if (flag > 1)
				return (0);
			x++;
		}
		x = 0;
		y++;
	}
	return (1);
}

/**
 * Determines if a character represents a valid element in the cub3D game map. Valid characters include '1' for walls, '0' for empty
 * space, '-' for undetermined spaces, and 'N', 'E', 'S', 'W' for player start positions facing North, East, South, and West,
 * respectively.
 * 
 * @param c The character to be checked.
 * @return 1 if the character is valid, 0 otherwise.
 */
int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == '-' || c == 'N' \
	|| c == 'E' || c == 'S' || c == 'W')
		return (1);
	return (0);
}
