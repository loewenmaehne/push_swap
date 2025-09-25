/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrotdown.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 17:39:39 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/05 12:52:21 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Rotate down list. Last element becomes first. (t_list)
 * 
 * @note Returns with no action when lst is empty or one element.
 * @warning 42 student
 */
void	ft_lstrotdown(t_list **lst)
{
	t_list	*last;
	t_list	*paene;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	paene = *lst;
	while ((paene)->next->next != NULL)
		paene = paene->next;
	last = paene->next;
	paene->next = NULL;
	last->next = *lst;
	*lst = last;
	ft_lstaddindex(*lst);
}
