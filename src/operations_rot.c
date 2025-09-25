/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:54:35 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/05 12:56:17 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Shift up all elements of stack a by one
 * 
 * @param a [in,out] Stack used to shift all elements one up.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @note The first element becomes the last one.
 * @warning 42 student
 */
void	ft_lst_ra(t_list **a)
{
	if (!a)
		return ;
	ft_lstrotup(a);
	ft_printf("ra\n");
}

/**
 * @brief Shift up all elements of stack b by one
 * 
 * @param b [in,out] Stack used to shift all elements one up.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @note The first element becomes the last one.
 * @warning 42 student
 */
void	ft_lst_rb(t_list **b)
{
	if (!b)
		return ;
	ft_lstrotup(b);
	ft_printf("rb\n");
}

/**
 * @brief Shift up all elements of stack a and b by one
 * 
 * @param a [in,out] Stack used to shift all elements one up.
 * @param b [in,out] Stack used to shift all elements one up.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @note The first element becomes the last one for both stacks each.
 * @warning 42 student
 */
void	ft_lst_rr(t_list **a, t_list **b)
{
	if (!a || !b)
		return ;
	ft_lstrotup(a);
	ft_lstrotup(b);
	ft_printf("rr\n");
}
