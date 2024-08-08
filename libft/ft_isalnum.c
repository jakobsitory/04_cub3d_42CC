/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:19:42 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:38:18 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if a character is alphanumeric.
 * 
 * This function, `ft_isalnum`, determines if a given character `c`, represented by an integer,
 * is alphanumeric, meaning it is either an alphabetic letter (a-z, A-Z) or a digit (0-9). It
 * leverages two other functions, `ft_isalpha` and `ft_isdigit`, to check for alphabetic and
 * numeric characters, respectively.
 * 
 * @param c The integer value of the character to be checked.
 * @return Returns 1 if `c` is an alphanumeric character, 0 otherwise.
 */
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}
