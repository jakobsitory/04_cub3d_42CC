/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:31:27 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/03 15:18:58 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(char *str)
{
	int	pos;
	int	count;

	pos = 0;
	count = 0;
	if (str == NULL)
	{
		count += ft_put_str("(null)");
		return (count);
	}
	while (str[pos] != '\0')
	{
		write(1, &str[pos], 1);
		pos++;
		count++;
	}
	return (count);
}
