/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:01:15 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/05 12:35:16 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstclone(t_list *lst)
{
	t_list	*start;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = ft_lstnew(lst->content);
	start = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = ft_lstnew(lst->content);
		if (!(tmp->next))
		{
			ft_lstclear(&start, free);
			return (NULL);
		}
		tmp = tmp->next;
	}
	ft_lstaddindex(start);
	return (start);
}
