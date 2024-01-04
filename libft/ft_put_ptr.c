/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:30:54 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/07/11 17:33:12 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_put_str("(nil)");
		return (count);
	}
	count += ft_put_str("0x");
	count += ft_write_ptr(n);
	return (count);
}

int	ft_write_ptr(uintptr_t n)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	while (n >= 16)
	{
		count += ft_write_ptr(n / 16);
		n = n % 16;
	}
	write(1, &base[n], 1);
	count++;
	return (count);
}
