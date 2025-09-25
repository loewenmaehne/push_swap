/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:01:34 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/15 13:58:19 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Final rotation to place stack in full ascending order
 * 
 * @param a [in,out] Sorted stack a to sort back in.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @warning 42 student
 */
void	ft_final_rot(t_list **a)
{
	int	index;
	int	len;

	index = ft_index_min_value(*a);
	len = ft_lstsize(*a);
	if (index < len - index)
	{
		while (index-- > 0)
			ft_lst_ra(a);
	}
	else
	{
		while (len - index++ > 0)
			ft_lst_rra(a);
	}
}

/**
 * @brief Sort in element with lowest cost from b back to a at right pos
 * 
 * @param a [in,out] Sorted stack a to sort back in.
 * @param b [in,out] Unsorted stack b to move and push element at index to a.
 * @param index [in] Index of chosen element in stack b.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @warning 42 student
 */
void	ft_sort_in_element(t_list **a, t_list **b, t_cost pick)
{
	int	strategy;

	strategy = pick.strategy;
	if (strategy == 0)
		ft_sort_in_ra_rb(a, b, pick);
	if (strategy == 1)
		ft_sort_in_rra_rrb(a, b, pick);
	if (strategy == 2)
		ft_sort_in_rra_rb(a, b, pick);
	if (strategy == 3)
		ft_sort_in_ra_rrb(a, b, pick);
}

/**
 * @brief Sort remaining three elements in stack a
 * 
 * @param a [in,out] Stack used to sort remaining three elements.
 *
 * @warning 42 student
 */
void	ft_sort_three(t_list **a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = *(int *)(*a)->content;
	num2 = *(int *)(*a)->next->content;
	num3 = *(int *)(*a)->next->next->content;
	if (num2 < num1 && num2 < num3)
		ft_lst_ra(a);
	if (num3 < num1 && num3 < num2)
		ft_lst_rra(a);
	num2 = *(int *)(*a)->next->content;
	num3 = *(int *)(*a)->next->next->content;
	if (num3 < num2)
	{
		ft_lst_sa(a);
		ft_lst_ra(a);
	}
}

/**
 * @brief Push all but three element from stack a to stack b
 * 
 * @param a [in,out] Stack used to push element from.
 * @param b [in,out] Stack used to push element to.
 *
 * @note Prints operation according to subject (42: push_swap).
 * @warning 42 student
 */
void	ft_push_all_but_three(t_list **a, t_list **b)
{
	int	len;

	len = ft_lstsize(*a);
	while (len-- > 3)
		ft_lst_pb(a, b);
}
