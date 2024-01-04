/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:54:38 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/05/13 13:52:46 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_put_nbr_hex(unsigned long long int nbr, char flag)
{
	int			count;
	char		*hexbase;

	if (flag == 'x')
		hexbase = "0123456789abcdef";
	else
		hexbase = "0123456789ABCDEF";
	count = 0;
	while (nbr >= 16)
	{
		count += ft_put_nbr_hex(nbr / 16, flag);
		nbr = nbr % 16;
	}
	write(1, &hexbase[nbr], 1);
	count++;
	return (count);
}
