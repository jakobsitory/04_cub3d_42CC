/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:17:24 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:36:22 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * Checks if a character is a lowercase alphabetic letter.
 * 
 * @param c The integer value of the character to be checked.
 * @return Returns 1 if `c` is a lowercase alphabetic letter, 0 otherwise.
 */
int	ft_islower(int c)
{
	if (('a' <= c) && (c <= 'z'))
		return (1);
	else
		return (0);
}

/**
 * Checks if a character is an uppercase alphabetic letter.
 * 
 * @param c The integer value of the character to be checked.
 * @return Returns 1 if `c` is an uppercase alphabetic letter, 0 otherwise.
 */
int	ft_isupper(int c)
{
	if (('A' <= c) && (c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * Checks if a character is an alphabetic letter.
 * 
 * @param c The integer value of the character to be checked.
 * @return Returns 1 if `c` is an alphabetic letter, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	if (ft_islower(c) || ft_isupper(c))
		return (1);
	else
		return (0);
}
