/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:22:01 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:12:15 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts a lowercase letter to uppercase.
 * 
 * This function checks if the input character `c` is a lowercase letter
 * and converts it to its uppercase equivalent if it is. The conversion
 * is based on the ASCII value difference between lowercase and uppercase
 * letters, which is 32. If `c` is not a lowercase letter, it is returned
 * unchanged.
 * 
 * @param c The character to convert, represented as an ASCII value.
 * @return The uppercase equivalent of `c` if it is a lowercase letter,
 *         otherwise `c` itself.
 */
int	ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	else
		return (c);
}
