/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:54:59 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/13 17:17:53 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Swap the first two elements at the top of stack a
 * 
 * @param a [in,out] Stack used to swap the top two elements.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @warning 42 student
 */
void	ft_lst_sa(t_list **a)
{
	if (!a)
		return ;
	ft_lstswap(a);
	ft_printf("sa\n");
}

/**
 * @brief Swap the first two elements at the top of stack b
 * 
 * @param b [in,out] Stack used to swap the top two elements.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @warning 42 student
 */
/*
void	ft_lst_sb(t_list **b)
{
	if (!b)
		return ;
	ft_lstswap(b);
	ft_printf("sb\n");
}
*/
/**
 * @brief Swap the first two elements at the top of stack a and b each.
 * 
 * @param a [in,out] Stack used to swap the top two elements.
 * @param b [in,out] Stack used to swap the top two elements.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @warning 42 student
 */
/*
void	ft_lst_ss(t_list **a, t_list **b)
{
	if (!a || !b)
		return ;
	ft_lstswap(a);
	ft_lstswap(a);
	ft_printf("ss\n");
}
*/