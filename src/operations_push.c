/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:39:14 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/10 15:11:50 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Push top element of stack b to the top of stack a
 * 
 * @param a [in,out] Stack used to push top element from.
 * @param b [in,out] Stack used to push top element to.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @warning 42 student
 */
void	ft_lst_pa(t_list **a, t_list **b)
{
	if (!a || !b)
		return ;
	ft_lstpush(b, a);
	ft_printf("pa\n");
}

/**
 * @brief Push top element of stack a to the top of stack b
 * 
 * @param b [in,out] Stack used to push top element to.
 * @param a [in,out] Stack used to push top element from.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @warning 42 student
 */
void	ft_lst_pb(t_list **a, t_list **b)
{
	if (!a || !b)
		return ;
	ft_lstpush(a, b);
	ft_printf("pb\n");
}
