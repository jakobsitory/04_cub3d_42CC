/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:05:41 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:29:18 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Creates a new list node with given content.
 * 
 * @param content The content to store in the new node. This can be a pointer to any type
 *                of data, or NULL if the node should not contain data initially.
 * @return A pointer to the newly created list node, or NULL if memory allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc (sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
