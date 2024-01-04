/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:17:57 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/05/09 12:27:01 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return ((char *)&s[len]);
		len--;
	}
	if (c == '\0')
		return ((char *)&s[len]);
	return ((char *) '\0');
}

/*
int	main(void)
{
	char str[] = "Hello Hello";
	printf("%s\n", ft_strrchr(str, 'e'));
	printf("%s\n", strrchr(str, 'e'));
}
*/