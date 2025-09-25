/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:53:14 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/15 13:39:27 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Sort in element from b to a using ra, rb and rr movements
 * 
 * @param a [in] Stack a to get element from stack b sorted in.
 * @param b [in] Stack b to sort element into stack a.
 * 
 * @warning 42 student
 */
void	ft_sort_in_ra_rb(t_list **a, t_list **b, t_cost pick)
{
	int	min;
	int	rest;
	int	i;

	min = ft_min(pick.index_a, pick.index_b);
	i = 0;
	while (i++ < min)
		ft_lst_rr(a, b);
	rest = ft_max(pick.index_a, pick.index_b) - min;
	i = 0;
	if (min == pick.index_a)
	{
		while (i++ < rest)
			ft_lst_rb(b);
	}
	else
	{
		while (i++ < rest)
			ft_lst_ra(a);
	}
	ft_lst_pa(a, b);
}

/**
 * @brief Sort in element from b to a using rra, rrb and rrr movements
 * 
 * @param a [in] Stack a to get element from stack b sorted in.
 * @param b [in] Stack b to sort element into stack a.
 * 
 * @warning 42 student
 */
void	ft_sort_in_rra_rrb(t_list **a, t_list **b, t_cost pick)
{
	int	min;
	int	moves_a;
	int	moves_b;
	int	rest;
	int	i;

	moves_a = ft_lstsize(*a) - pick.index_a;
	moves_b = ft_lstsize(*b) - pick.index_b;
	min = ft_min(moves_a, moves_b);
	i = 0;
	while (i++ < min)
		ft_lst_rrr(a, b);
	rest = ft_max(moves_a, moves_b) - min;
	i = 0;
	if (min == moves_a)
	{
		while (i++ < rest)
			ft_lst_rrb(b);
	}
	else
	{
		while (i++ < rest)
			ft_lst_rra(a);
	}
	ft_lst_pa(a, b);
}

/**
 * @brief Sort in element from b to a using rra and rb movements
 * 
 * @param a [in] Stack a to get element from stack b sorted in.
 * @param b [in] Stack b to sort element into stack a.
 * 
 * @warning 42 student
 */
void	ft_sort_in_rra_rb(t_list **a, t_list **b, t_cost pick)
{
	int	moves_a;
	int	i;

	moves_a = ft_lstsize(*a) - pick.index_a;
	i = 0;
	while (i++ < moves_a)
		ft_lst_rra(a);
	i = 0;
	while (i++ < pick.index_b)
		ft_lst_rb(b);
	ft_lst_pa(a, b);
}

/**
 * @brief Sort in element from b to a using ra and rrb movements
 * 
 * @param a [in] Stack a to get element from stack b sorted in.
 * @param b [in] Stack b to sort element into stack a.
 * 
 * @warning 42 student
 */
void	ft_sort_in_ra_rrb(t_list **a, t_list **b, t_cost pick)
{
	int	moves_b;
	int	i;

	moves_b = ft_lstsize(*b) - pick.index_b;
	i = 0;
	while (i++ < pick.index_a)
		ft_lst_ra(a);
	i = 0;
	while (i++ < moves_b)
		ft_lst_rrb(b);
	ft_lst_pa(a, b);
}
