/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:24:14 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:30:56 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Adds a new element to the front of a list.
 * 
 * @param lst A pointer to the pointer to the head of the list. This double pointer allows
 *            the function to modify the caller's pointer to the head of the list.
 * @param new The new element to be added to the front of the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
