/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddindex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:25:52 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/05 12:54:08 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Add index to all nodes in a list starting from zero (t_list)
 * 
 * @param lst [in, out] List to be indexed.
 * 
 * @warning 42 student
 */
void	ft_lstaddindex(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst->index = i++;
		lst = lst->next;
	}
}
