/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:20:09 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:34:48 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if a character is printable.
 * 
 * @param c The integer value of the character to be checked.
 * @return Returns 1 if `c` is a printable character, 0 otherwise.
 */
int	ft_isprint(int c)
{
	if ((32 <= c) && (c <= 126))
		return (1);
	else
		return (0);
}
