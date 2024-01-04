/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:21:33 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/05/10 13:28:37 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*s1u;
	unsigned char	*s2u;
	unsigned int	i;

	s1u = (unsigned char *)s1;
	s2u = (unsigned char *)s2;
	i = 0;
	while ((s1u[i] || s2u[i]) && (i < n))
	{
		if (s1u[i] < s2u[i])
			return (-1);
		else if (s1u[i] > s2u[i])
			return (1);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	printf("%i\n", ft_strncmp("Hallo", "Halz", 5));
	printf("%i\n", strncmp("Hallo", "Halz", 5));
	printf("%i\n", ft_strncmp("Hal", "Hallo", 5));
	printf("%i\n", strncmp("Hal", "Hallo", 5));
	printf("%i\n", ft_strncmp("", "", 5));
	printf("%i\n", strncmp("", "", 5));
}
*/
