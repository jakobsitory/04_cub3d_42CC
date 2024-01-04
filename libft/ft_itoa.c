/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:13:09 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/05/10 12:17:18 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_no_chars(long int n)
{
	int	chars;

	chars = 1;
	if (n < 0)
	{
		n = -n;
		chars++;
	}
	while (n >= 10)
	{
		chars++;
		n /= 10;
	}
	return (chars);
}

void	convert_digits(char *res, long nb, int flag, int chars)
{
	while (chars-- > flag)
	{
		res[chars] = nb % 10 + '0';
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	char		*res;
	int			chars;
	int			flag;
	long int	nb;

	flag = 0;
	res = NULL;
	nb = n;
	chars = get_no_chars(nb);
	if (n < 0)
	{
		nb = -(long int)n;
		flag = 1;
	}
	res = malloc((chars + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[chars] = '\0';
	convert_digits(res, nb, flag, chars);
	if (flag)
		res[0] = '-';
	return (res);
}

/* int	main(void)
{
	int i = -2147483648LL;
	char *res = ft_itoa(i);
	printf("%s\n", res);
} */