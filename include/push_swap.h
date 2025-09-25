/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:19:33 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/13 17:30:04 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../ft_printf/include/ft_printf.h"

typedef struct t_cost
{
	int	cost;
	int	index_a;
	int	index_b;
	int	strategy;
}		t_cost;

int		main(int argc, char **argv);
void	ft_lst_sa(t_list **a);
void	ft_lst_pa(t_list **a, t_list **b);
void	ft_lst_pb(t_list **a, t_list **b);
void	ft_lst_ra(t_list **a);
void	ft_lst_rb(t_list **b);
void	ft_lst_rr(t_list **a, t_list **b);
void	ft_lst_rra(t_list **a);
void	ft_lst_rrb(t_list **b);
void	ft_lst_rrr(t_list **a, t_list **b);
void	ft_push_all_but_three(t_list **a, t_list **b);
void	ft_sort_three(t_list **a);
void	ft_sort_in_element(t_list **a, t_list **b, t_cost pick);
int		ft_is_stack_ascend_circular(t_list *lst);
void	ft_final_rot(t_list **a);
int		ft_sorted_pos(t_list *lst, t_list *element);
t_cost	ft_candidate_ra_rb(t_list *a, t_list *b);
t_cost	ft_candidate_rra_rrb(t_list *a, t_list *b);
t_cost	ft_candidate_rra_rb(t_list *a, t_list *b);
t_cost	ft_candidate_ra_rrb(t_list *a, t_list *b);
t_cost	ft_pick_lowest_cost(t_list *a, t_list *b);
void	ft_sort_in_ra_rb(t_list **a, t_list **b, t_cost pick);
void	ft_sort_in_rra_rrb(t_list **a, t_list **b, t_cost pick);
void	ft_sort_in_rra_rb(t_list **a, t_list **b, t_cost pick);
void	ft_sort_in_ra_rrb(t_list **a, t_list **b, t_cost pick);
int		ft_index_min_value(t_list *a);
#endif