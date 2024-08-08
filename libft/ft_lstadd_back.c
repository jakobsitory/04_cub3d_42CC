/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:15:37 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:31:12 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Adds a new element to the end of a list.
 * 
 * @param lst A pointer to the pointer to the head of the list. This double pointer allows
 *            the function to modify the caller's pointer to the head of the list.
 * @param new The new element to be added to the end of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pos;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	pos = ft_lstlast(*lst);
	pos->next = new;
}
