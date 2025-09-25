/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 16:28:38 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/10 14:43:14 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Rotate up list. First element becomes last. (t_list)
 * 
 * @note Returns with no action when lst is empty or one element.
 * @warning 42 student
 */
void	ft_lstrotup(t_list **lst)
{
	t_list	*new_first;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	last = ft_lstlast(*lst);
	new_first = (*lst)->next;
	last->next = *lst;
	(*lst)->next = NULL;
	*lst = new_first;
	ft_lstaddindex(*lst);
}
