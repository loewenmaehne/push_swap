/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:12:30 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/05 12:36:54 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Creates a new list with a first node (t_list)
 * 
 * @param content [in] Content of first node (void *). Can be NULL.
 * @return t_list Pointer to first node, the beginning of the list.
 * 
 * @note Next node is NULL.
 * @warning Caller must free().
 * @warning 42 student
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->index = 0;
	return (node);
}
