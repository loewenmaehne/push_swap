/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlastindex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 17:31:36 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/13 17:16:37 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/**
 * @brief Highest index in a lst (t_list)
 * 
 * @param lst [in] The beginning of the list.
 * @return Highest index or 0 on NULL.
 * 
 * @note Lst might start at index > 0.
 * @warning 42 student
 */
int	ft_lstlastindex(t_list *lst)
{
	int	index;

	if (!lst)
		return (0);
	index = -1;
	while (lst != NULL)
	{
		index = lst->index;
		lst = lst->next;
	}
	return (index);
}
