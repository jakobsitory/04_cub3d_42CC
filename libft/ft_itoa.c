/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:15:14 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:34:32 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Swaps the values of two characters.
 * 
 * @param tab1 Pointer to the first character to be swapped.
 * @param tab2 Pointer to the second character to be swapped.
 */
void	ft_swap(char *tab1, char *tab2)
{
	char	memory;

	memory = *tab1;
	*tab1 = *tab2;
	*tab2 = memory;
}

/**
 * Reverses a string in place.
 * 
 * @param tab The string to be reversed.
 * @param size The size of the string.
 */
void	ft_revstr(char *tab, int size)
{
	int	i;

	i = 0;
	while (i <= size / 2 - 1)
	{
		ft_swap(&tab[i], &tab[size - 1 - i]);
		i++;
	}
}

/**
 * Recursively fills a string with the digits of a long integer.
 * 
 * @param str The string buffer where the digits of `n` will be stored.
 * @param n The long integer to be converted into a string.
 */
void	ft_iina(char *str, long int n)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_iina(&str[1], n / 10);
	str[0] = n % 10 + '0';
}

/**
 * Calculates the number of digits in a long integer.
 * 
 * @param nb The long integer whose digits are to be counted.
 * @return The number of digits in `nb`.
 */
int	ft_itodigs(long int nb)
{
	int			digits;

	digits = 1;
	while (nb >= 10)
	{
		digits++;
		nb = nb / 10;
	}
	return (digits);
}

/**
 * Converts an integer to its string representation.
 * 
 * @param n The integer to convert.
 * @return A pointer to the string representing the integer, or NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	char		*str;
	int			digits;
	long int	nb;
	int			sign;

	nb = (long int) n;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		nb = -(long int)n;
	}
	digits = ft_itodigs(nb);
	str = (char *) malloc (digits + sign + 1);
	if (str == NULL)
		return (NULL);
	if (sign && nb != 0)
		str[0] = '-';
	if (nb == 0)
		str[0] = '0';
	else
		ft_iina(&str[sign], (long int) n);
	ft_revstr(&str[sign], digits);
	str[digits + sign] = '\0';
	return (str);
}
