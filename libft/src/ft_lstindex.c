/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:53:40 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/10 13:29:15 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Return node by index (t_list)
 * 
 * @param lst [in] The list to find index at.
 * @param index [in] The index of the wanted node.
 * 
 * @warning 42 student
 */
t_list	*ft_lst_index(t_list *lst, int index)
{
	while (lst)
	{
		if (lst->index == index)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
