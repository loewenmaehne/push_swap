/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:30:09 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/05 12:48:52 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Move the first element of a list to another lists front (t_list)
 * 
 * @param from [in, out] Front node to be moved.
 * @param to [in, out] Destination for node to be moved on top of lst.
 * 
 * @note Only moves the first node in lst.
 * @note Returns without action when no node given.
 * @note Works when destiation lst is empty (NULL).
 * @warning 42 student
 */
void	ft_lstpush(t_list **from, t_list **to)
{
	t_list	*second;

	if (!from || !*from || !to)
		return ;
	second = (*from)->next;
	ft_lstadd_front(to,*from);
	*from = second;
	ft_lstaddindex(*from);
}
