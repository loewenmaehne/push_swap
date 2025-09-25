/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:09:51 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/25 13:46:35 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

/**
 * @brief Get the index of the element with the lowest integer val
 * 
 * @param a [in] Stack a to find lowest integer value for.
 * 
 * @warning 42 student
 */
int	ft_index_min_value(t_list *a)
{
	int	min;
	int	index;

	index = ft_lstlastindex(a);
	min = INT_MAX;
	while (a)
	{
		if (*(int *)a->content < min)
		{
			min = *(int *)a->content;
			index = a->index;
		}
		a = a->next;
	}
	return (index);
}

/**
 * @brief Checks if stack is sorted in ascending order
 * 
 * @param lst [in,out] Stack to examine.
 * @return int Returns 1 if stack is sorted in ascending order. 0 if not.
 *
 * @warning 42 student
 */
int	ft_is_stack_ascend_circular(t_list *lst)
{
	int	decreases;
	int	prev;
	int	start;

	prev = INT_MIN;
	decreases = 0;
	start = *(int *)lst->content;
	while (lst)
	{
		if (prev > *(int *)lst->content)
			decreases++;
		prev = *(int *)lst->content;
		lst = lst->next;
	}
	if (prev > start)
		decreases++;
	return (decreases < 2);
}

/*
void	ft_print_stack(t_list *lst)
{
	t_list	*tmp;
	int		num;

	tmp = lst;
	ft_printf("\n");
	while (tmp)
	{
		num = *(int *)(tmp->content);
		ft_printf("%d ", num);
		tmp = tmp->next;
	}
	ft_printf("\n");
}
*/