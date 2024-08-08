/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:15:49 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:54:43 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Prints a string to the standard output, handling NULL pointers gracefully.
 * 
 * @param str A void pointer to the string to be printed. Can be NULL.
 * @return The number of characters printed to the standard output.
 */
int	ft_prints(void *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd((char *)str, 1);
	return (ft_strlen((char *)str));
}
