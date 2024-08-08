/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:24:32 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:26:03 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Writes a single character to a given file descriptor.
 * 
 * @param c The character to write.
 * @param fd The file descriptor to which the character is written.
 */
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
