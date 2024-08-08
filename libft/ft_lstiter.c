/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:30:47 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:30:12 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterates over a list and applies a function to the content of each element.
 * 
 * @param lst The head of the list to iterate over.
 * @param f The function to apply to each element's content.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*pos;

	pos = lst;
	while (pos)
	{
		f(pos->content);
		pos = pos->next;
	}
}
