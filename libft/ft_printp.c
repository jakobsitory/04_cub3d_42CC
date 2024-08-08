/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:15:49 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:54:30 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Prints a pointer address to the standard output.
 * 
 * @param ptr The pointer whose memory address is to be printed.
 * @return The number of characters printed to the standard output.
 */
int	ft_printp(void *ptr)
{
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	return (ft_prints("0x") + ft_printx('x', (unsigned long long int)ptr));
}
