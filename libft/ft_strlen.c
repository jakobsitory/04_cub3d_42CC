/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:20:28 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:20:47 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Calculates the length of a string.
 * 
 * @param str The string whose length is to be calculated.
 * @return The number of characters in `str` before the terminating null byte.
 */
int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
