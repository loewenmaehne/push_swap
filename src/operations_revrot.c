/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_revrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:59:09 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/24 17:08:11 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Shift down all elements of stack a by one
 * 
 * @param a [in,out] Stack used to shift all elements one down.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @note The last element becomes the first one.
 * @warning 42 student
 */
void	ft_lst_rra(t_list **a)
{
	if (!a)
		return ;
	ft_lstrotdown(a);
	ft_printf("rra\n");
}

/**
 * @brief Shift down all elements of stack b by one
 * 
 * @param b [in,out] Stack used to shift all elements one down.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @note The last element becomes the first one.
 * @warning 42 student
 */
void	ft_lst_rrb(t_list **b)
{
	if (!b)
		return ;
	ft_lstrotdown(b);
	ft_printf("rrb\n");
}

/**
 * @brief Shift down all elements of stack a and b by one
 * 
 * @param a [in,out] Stack used to shift all elements one down.
 * @param b [in,out] Stack used to shift all elements one down.
 * 
 * @note Prints operation according to subject (42: push_swap).
 * @note The last element becomes the first one for both stacks each.
 * @warning 42 student
 */
void	ft_lst_rrr(t_list **a, t_list **b)
{
	if (!a || !b)
		return ;
	ft_lstrotdown(a);
	ft_lstrotdown(b);
	ft_printf("rrr\n");
}
