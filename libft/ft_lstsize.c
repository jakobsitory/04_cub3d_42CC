/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:39:09 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:29:04 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Counts the number of elements in a linked list.
 * 
 * @param lst Pointer to the first node of the linked list.
 * @return The number of nodes in the linked list.
 */
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	count++;
	if (lst->next != NULL)
		count = count + ft_lstsize(lst->next);
	return (count);
}
