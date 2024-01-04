/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:59:20 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/01 11:17:55 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_put_nbr_hex(int nbr, char flag);
int		ft_put_char(char c);
int		ft_put_str(char *str);
int		ft_put_ptr(unsigned long long n);
int		ft_put_nbr(int n);
int		ft_write_ptr(uintptr_t num);
int		ft_put_unsigned(unsigned int n);
//void	ft_itoa_printf(unsigned int n);

#endif