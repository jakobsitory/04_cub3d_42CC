/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:15:49 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:54:40 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Recursively prints an unsigned integer to a given file descriptor.
 * 
 * @param n The unsigned integer to be printed.
 * @param fd The file descriptor to which `n` is printed.
 */
void	ft_putunsigned_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putunsigned_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

/**
 * Prints an unsigned integer to the standard output and returns the number of digits.
 * 
 * @param i The unsigned integer to be printed.
 * @return The number of digits in `i`.
 */
int	ft_printu(long int i)
{
	ft_putunsigned_fd(i, 1);
	return (ft_itodigs((long int) i));
}
