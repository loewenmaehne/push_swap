/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:45:04 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/05 12:36:27 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Create new t_list with results of f() on each original lists content
 * 
 * @param lst [in, out] List with content to form new lists content through f().
 * @param f [in] Function to apply on original list to form new lists content.
 * @param del [in] Function to run to delete all new nodes content on failure.
 * 
 * @note Original list stays the same.
 * @warning 42 student
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = ft_lstnew(f(lst->content));
	if (!tmp)
		return (NULL);
	start = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(f(lst->content));
		if (!(tmp->next))
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	ft_lstaddindex(start);
	return (start);
}
