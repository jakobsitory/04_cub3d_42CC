/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:19:00 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/05/10 12:31:36 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destptr;
	char	*srcptr;
	size_t	i;

	destptr = (char *)dest;
	srcptr = (char *)src;
	if (!destptr && !srcptr)
		return (dest);
	i = 0;
	if (src < dest)
	{
		while (i < n)
		{
			destptr[n - 1 - i] = srcptr[n - 1 - i];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*
int	main(void)
{
	char str[] = "Hello";
	char str2[] = "Hello";
	char src[] = "Byeeeee";
	printf("%s\n", str);
	printf("%s\n", str2);
	ft_memmove(str, src, 5);
	memmove(str2, src, 5);
	printf("%s\n", str);
	printf("%s\n", str2);
}
*/
