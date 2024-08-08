/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:33:53 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:07:41 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Checks if the given character is a sign ('+' or '-').
 * 
 * @param c The character to check.
 * @return 1 if the character is '+', -1 if it is '-', and 0 otherwise.
 */
int	ft_issign(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	else
		return (0);
}

/**
 * Determines if the given character is a whitespace character.
 * Whitespace characters include ' ', '\t', '\n', '\v', '\f', and '\r'.
 * 
 * @param c The character to check.
 * @return 1 if the character is a whitespace, 0 otherwise.
 */
int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

/**
 * Converts a string of digits into an integer.
 * The conversion stops at the first non-digit character or at the end of the string.
 * 
 * @param str The string to convert.
 * @return The integer value of the number represented by the string.
 *         Returns 0 if the string does not start with a digit.
 */
int	ft_toint(const char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]) != 0)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb);
}

/**
 * Converts a string to an integer.
 * The function skips leading whitespace characters, then takes an optional '+' or '-'
 * sign followed by as many numerical digits as possible to form an integer.
 * 
 * @param str The string to convert.
 * @return The int representation of the number in the string.
 *         The function is incomplete and needs further implementation to handle signs
 *         and return the converted integer.
 */
int	ft_atoi(const char *str)
{
	int	i;
	int	s;

	i = 0;
	s = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		s = ft_issign(str[i]);
		i++;
	}
	if (ft_isdigit(str[i]))
		return (s * ft_toint(&str[i]));
	else
		return (0);
}
