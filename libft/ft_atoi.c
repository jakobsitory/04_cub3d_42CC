/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:21:44 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/23 13:03:12 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *nptr)
{
	int			i;
	long int	number;
	int			multiplier;

	number = 0;
	i = 0;
	multiplier = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			multiplier = multiplier * (-1);
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	return (multiplier * number);
}

/* #include "limits.h"
#include "stdio.h"

int	main(void)
{
	//char	test1[] = "";
	printf("%li\n", ft_atoi("2147483649000"));
	printf("%i\n", atoi("-2147483649"));
	return (0);
}
 */
