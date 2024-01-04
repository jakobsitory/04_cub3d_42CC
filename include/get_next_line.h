/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leon <leon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:29:26 by lgrimmei          #+#    #+#             */
/*   Updated: 2023/08/05 15:09:23 by leon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//DELETE:
# include <fcntl.h>

char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(const char *s);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
int		ft_no_newline(const char *s);

#endif