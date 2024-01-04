/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:41:12 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/23 12:52:27 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((int)(nmemb * size));
	if (!ptr)
		return (NULL);
	while (i < (int)(nmemb * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
