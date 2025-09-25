/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 21:43:44 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/05 12:47:19 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Run del function to remove content then free the node (t_list)
 * 
 * @param lst [in, out] Node to be freed.
 * @param del [in] Function to run to delete node content.
 * 
 * @note Caller must relink predecessor to successor and update index.
 * @warning 42 student
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
