/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:15:49 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:54:16 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Prints a character to the standard output.
 * 
 * @param c The character to be printed, passed as an integer but cast to a char within the function.
 * @return Always returns 1, indicating the number of characters printed.
 */
int	ft_printc(int c)
{
	ft_putchar_fd((char) c, 1);
	return (1);
}
