/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:22:34 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:15:50 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts a uppercase letter to lowercase.
 * 
 * This function checks if the input character `c` is a uppercase letter
 * and converts it to its lowercase equivalent if it is. The conversion
 * is based on the ASCII value difference between uppercase and lowercase
 * letters, which is 32. If `c` is not a uppercase letter, it is returned
 * unchanged.
 * 
 * @param c The character to convert, represented as an ASCII value.
 * @return The lowercase equivalent of `c` if it is a uppercase letter,
 *         otherwise `c` itself.
 */
int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	else
		return (c);
}
