/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   consider_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:09:10 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/15 13:37:24 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

/**
 * @brief Calculate cost for ra and rrb movements
 * 
 * @param a [in] Stack a to partially calculate costs with.
 * @param b [in] Stack b to partially calculate costs with.
 * @return t_cost struct with cost, index_a, index_b and strategy.
 * 
 * @warning 42 student
 */
t_cost	ft_candidate_ra_rrb(t_list *a, t_list *b)
{
	t_cost	candidate;
	int		pos_a;
	int		len_b;

	candidate.cost = 0;
	pos_a = ft_sorted_pos(a, b);
	len_b = ft_lstlastindex(b) + 1;
	candidate.cost = pos_a + len_b - b->index;
	candidate.index_a = pos_a;
	candidate.index_b = b->index;
	candidate.strategy = 3;
	return (candidate);
}

/**
 * @brief Calculate cost for rra and rb movements
 * 
 * @param a [in] Stack a to partially calculate costs with.
 * @param b [in] Stack b to partially calculate costs with.
 * @return t_cost struct with cost, index_a, index_b and strategy.
 * 
 * @warning 42 student
 */
t_cost	ft_candidate_rra_rb(t_list *a, t_list *b)
{
	t_cost	candidate;
	int		pos_a;
	int		len_a;

	candidate.cost = 0;
	len_a = ft_lstsize(a);
	pos_a = ft_sorted_pos(a, b);
	if (!pos_a)
		pos_a = len_a;
	candidate.cost = len_a - pos_a + b->index;
	candidate.index_a = pos_a;
	candidate.index_b = b->index;
	candidate.strategy = 2;
	return (candidate);
}

/**
 * @brief Calculate cost for rra, rrb and rrr movements
 * 
 * @param a [in] Stack a to partially calculate costs with.
 * @param b [in] Stack b to partially calculate costs with.
 * @return t_cost struct with cost, index_a, index_b and strategy.
 * 
 * @warning 42 student
 */
t_cost	ft_candidate_rra_rrb(t_list *a, t_list *b)
{
	t_cost	candidate;
	int		pos_a;
	int		len_a;
	int		len_b;
	int		min;

	candidate.cost = 0;
	pos_a = ft_sorted_pos(a, b);
	len_a = ft_lstsize(a);
	if (!pos_a)
		pos_a = len_a;
	len_b = ft_lstlastindex(b) + 1;
	min = ft_min(len_b - b->index, len_a - pos_a);
	candidate.cost = len_b - b->index + len_a - pos_a - min;
	candidate.index_a = pos_a;
	candidate.index_b = b->index;
	candidate.strategy = 1;
	return (candidate);
}

/**
 * @brief Calculate cost for ra, rb and rr movements
 * 
 * @param a [in] Stack a to partially calculate costs with.
 * @param b [in] Stack b to partially calculate costs with.
 * @return t_cost struct with cost, index_a, index_b and strategy.
 * 
 * @warning 42 student
 */
t_cost	ft_candidate_ra_rb(t_list *a, t_list *b)
{
	t_cost	candidate;
	int		pos_a;
	int		pos_b;

	candidate.cost = 0;
	pos_a = ft_sorted_pos(a, b);
	pos_b = b->index;
	candidate.cost = pos_a + pos_b - ft_min(pos_a, pos_b);
	candidate.index_a = ft_sorted_pos(a, b);
	candidate.index_b = pos_b;
	candidate.strategy = 0;
	return (candidate);
}
