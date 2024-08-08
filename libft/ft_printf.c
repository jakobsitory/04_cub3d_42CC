/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:43:43 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:54:22 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * Handles formatting and printing of various data types based on format specifiers.
 * 
 * @param c Pointer to the format specifier character.
 * @param arg The variable argument list containing the data to be printed.
 * @return The number of characters printed, or 1 if a percent sign is printed.
 */
int	check_type(const char *c, va_list arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (0);
	if (*c == 'c')
		i += ft_printc(va_arg(arg, int));
	else if (*c == 's')
		i += ft_prints(va_arg(arg, void *));
	else if (*c == 'p')
		i += ft_printp(va_arg(arg, void *));
	else if (*c == 'd' || *c == 'i')
		i += ft_printi(va_arg(arg, int));
	else if (*c == 'u')
		i += ft_printu((unsigned int)va_arg(arg, unsigned int));
	else if (*c == 'x' || *c == 'X')
		i += ft_printx(c[0], va_arg(arg, unsigned int));
	else
		return (write(1, "%%", 1));
	return (i);
}

/**
 * Custom implementation of the printf function.
 * 
 * @param format The format string containing text to be printed and format specifiers.
 * @param ... Variable arguments corresponding to the format specifiers in `format`.
 * @return The total number of characters printed.
 */
int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	count = 0;
	i = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
			count += write (1, &format[i++], 1);
		if (format[i] == '%') 
		{
			if (format[++i] == '\0')
				return (-1);
			count += check_type(&format[i], args);
			if (ft_strchr("cspdiuxX%%", format[i]))
				i++;
		}
	}
	va_end(args);
	return (count);
}
