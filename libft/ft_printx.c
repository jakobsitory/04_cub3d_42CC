/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:15:49 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:54:38 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Calculates the number of digits in a hexadecimal representation of an unsigned long integer.
 * 
 * @param nb The number to be converted to hexadecimal.
 * @return The number of hexadecimal digits in `nb`.
 */
int	ft_xtodigs(unsigned long int nb)
{
	int			digits;

	digits = 1;
	if (nb < 0)
	{
		digits++;
		nb = -nb;
	}
	while (nb >= 16)
	{
		digits++;
		nb = nb / 16;
	}
	return (digits);
}

/**
 * Recursively prints an unsigned long long integer in a specified base.
 * 
 * @param nbr The number to be printed.
 * @param base A string containing the digits of the base in which `nbr` is to be printed.
 */
void	ft_putnbr_base(unsigned long long int nbr, char *base)
{
	if (nbr / ft_strlen(base) > 0)
	{
		ft_putnbr_base (nbr / ft_strlen(base), base);
		write (1, &base[nbr % ft_strlen(base)], 1);
	}
	else
		write (1, &base[nbr % ft_strlen(base)], 1);
}

/**
 * Prints an unsigned long long integer in hexadecimal format.
 * 
 * @param c A character indicating whether to use lowercase ('x') or uppercase ('X') hexadecimal digits.
 * @param h The number to be printed in hexadecimal format.
 * @return The number of digits in the hexadecimal representation of `h`.
 */
int	ft_printx(char c, unsigned long long int h)
{
	if (c == 'x')
		ft_putnbr_base(h, "0123456789abcdef");
	if (c == 'X')
		ft_putnbr_base(h, "0123456789ABCDEF");
	return (ft_xtodigs(h));
}
