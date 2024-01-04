/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:03:35 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/05/04 13:08:14 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*destptr;
	char	*srcptr;
	size_t	i;

	destptr = (char *)dest;
	srcptr = (char *)src;
	i = 0;
	if (!destptr && !srcptr)
		return (dest);
	while (i < n)
	{
		destptr[i] = srcptr[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	char str[] = "";
	char str2[] = "";
	char src[] = "";
	printf("%s\n", str);
	printf("%s\n", str2);
	ft_memcpy((void*)0, (void*)0, 1);
	memcpy((void*)0, (void*)0, 1);
	printf("%s\n", str);
	printf("%s\n", str2);
}
*/
