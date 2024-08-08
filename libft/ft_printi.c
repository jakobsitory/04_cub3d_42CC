/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:15:49 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:54:27 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Prints an integer to the standard output and returns the number of digits.
 * 
 * @param i The integer to be printed.
 * @return The number of digits in `i`.
 */
int	ft_printi(int i)
{
	ft_putnbr_fd(i, 1);
	if (i < 0)
		return (ft_itodigs((long int)i));
	else
		return (ft_itodigs((long int) i));
}
