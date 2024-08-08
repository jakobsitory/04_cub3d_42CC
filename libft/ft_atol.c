/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:33:53 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:54:33 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts a string to a long integer.
 * 
 * @param str The string to be converted.
 * @return The converted long integer, or 0 if no conversion could be performed.
 */
long	ft_toli(const char *str)
{
	int		i;
	long	nb;

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
 * Converts a string to a long integer, considering leading whitespace and sign.
 * 
 * @param str The string to be converted.
 * @return The converted long integer, or 0 if no conversion could be performed.
 */
long	ft_atol(const char *str)
{
	long int	i;
	long int	s;

	i = 0;
	s = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		s = (long) ft_issign(str[i]);
		i++;
	}
	if (ft_isdigit(str[i]))
		return (s * ft_toli(&str[i]));
	else
		return (0);
}
