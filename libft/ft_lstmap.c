/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:36:55 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:29:43 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Applies a function to the content of each element of a list, creating a new list.
 * 
 * @param lst The original list to map over.
 * @param f The function to apply to each element's content.
 * @param del The function to delete the content of an element if needed.
 * @return A new list with each element's content being the result of applying `f` to the original
 *         element's content, or NULL if an error occurs.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newlstel;

	if (!f || !lst || !del)
		return (NULL);
	newlstel = ft_lstnew(f(lst->content));
	if (!newlstel)
	{
		del(newlstel->content);
		return (NULL);
	}
	newlst = newlstel;
	lst = lst->next;
	while (lst)
	{
		newlstel = ft_lstnew(f(lst->content));
		if (!newlstel)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newlstel);
		lst = lst->next;
	}
	return (newlst);
}
