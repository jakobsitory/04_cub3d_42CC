/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:38:12 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/05/03 13:14:57 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	character;
	char	*ptr;
	size_t	i;

	character = c;
	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = character;
		i++;
	}
	return (ptr);
}

/*
int	main(void)
{
	char str[] = "Hello Hello";
	printf("%s\n", str);
	ft_memset(str, '$', 5);
	printf("%s\n", str);
}
*/