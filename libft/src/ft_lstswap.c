/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:23:22 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/19 13:23:47 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Swap the first two elements in a list (t_list)
 * 
 * @param lst [in, out] Pointer to the list to swap the first two elements with.
 *
 * @note Returns without action when no or one node given.
 * @warning 42 student
 */
void	ft_lstswap(t_list **lst)
{
	t_list	*second;
	int		tmp_index;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	second = (*lst)->next;
	(*lst)->next = (*lst)->next->next;
	second->next = *lst;
	*lst = second;
	tmp_index = (*lst)->index;
	(*lst)->index = (*lst)->next->index;
	(*lst)->next->index = tmp_index;
}
