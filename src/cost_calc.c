/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 19:59:40 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/15 13:33:04 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

/**
 * @brief Find max value in a lst
 * 
 * @param lst [in] List to find highest integer from content.
 * @return int Highest integer value in any of the lst elements.
 * 
 * @warning 42 student
 * @warning Content of t_list must be all integers.
 */
static int	ft_max_value(t_list *lst)
{
	int	max;

	max = INT_MIN;
	while (lst)
	{
		if (*(int *) lst->content > max)
			max = *(int *) lst->content;
		lst = lst->next;
	}
	return (max);
}

/**
 * @brief Correct position for element in a circular ascending lst
 * 
 * @param lst [in] Circular ascending list.
 * @param element [in] Element to find correct position in lst.
 * @return int Index of the position to fit element in lst.
 * 
 * @warning 42 student
 * @warning Content of t_list must be all integers.
 */
int	ft_sorted_pos(t_list *lst, t_list *element)
{
	t_list	*orig_start;
	int		index_low;
	int		i;

	orig_start = lst;
	index_low = ft_index_min_value(lst);
	if (*(int *)element->content > ft_max_value(lst))
		return (index_low);
	while (lst->index != index_low)
		lst = lst->next;
	i = 0;
	while (i < 2)
	{
		if (i == 1)
			lst = orig_start;
		while (lst)
		{
			if (*(int *)lst->content > *(int *)element->content)
				return (lst->index);
			lst = lst->next;
		}
		i++;
	}
	return (index_low);
}

/**
 * @brief Finds the candidate in b with the lowest cost to move to a (t_cost)
 * 
 * @param a [in] Lst to be sorted in from b.
 * @param b [in] Lst to pick best element to be sorted in a.
 * @return t_cost struct with cost, index_a, index_b and strategy.
 * 
 * @warning 42 student
 */
t_cost	ft_pick_lowest_cost( t_list *a, t_list *b)
{
	t_cost	candidate;
	t_cost	pick;
	int		len_a;
	int		len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstlastindex(b) + 1;
	pick.cost = INT_MAX;
	while (b)
	{
		if (ft_sorted_pos(a, b) <= len_a / 2 && b->index <= len_b / 2)
			candidate = ft_candidate_ra_rb(a, b);
		else if (ft_sorted_pos(a, b) > len_a / 2 && b->index > len_b / 2)
			candidate = ft_candidate_rra_rrb(a, b);
		else if (ft_sorted_pos(a, b) > len_a / 2 && b->index <= len_b / 2)
			candidate = ft_candidate_rra_rb(a, b);
		else
			candidate = ft_candidate_ra_rrb(a, b);
		if (candidate.cost < pick.cost)
			pick = candidate;
		b = b->next;
	}
	return (pick);
}
