/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:25:24 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/05/10 13:25:39 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	if (!n)
		return (NULL);
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char s[] = {0, 1, 2 ,3 ,4 ,5};
	char *res1 = memchr(s, 2, 4);
	printf("%s\n", res1);
	char *res2 = ft_memchr(s, 2, 4);
	printf("%s\n", res2);
}
 */