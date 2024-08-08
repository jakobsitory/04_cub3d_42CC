/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:19:53 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:37:37 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if a character is part of the ASCII character set.
 * 
 * @param c The integer value of the character to be checked.
 * @return Returns 1024 if `c` is part of the ASCII character set, 0 otherwise.
 */
int	ft_isascii(int c)
{
	if (((000 <= c) && (c <= 127)))
		return (1);
	else
		return (0);
}
