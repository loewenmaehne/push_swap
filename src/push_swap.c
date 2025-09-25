/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:36:47 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/16 12:55:05 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Free list and content and return error in terminal!
 * 
 * @param lst [in,out] List with content to be both freed.
 *
 * @note Helper function for push_swap only.
 * @warning 42 student
 */
static void	ft_exit_on_error(t_list *lst)
{
	if (lst)
		ft_lstclear(&lst, free);
	write(2, "Error\n", 6);
	exit(1);
}

/**
 * @brief Create a new node with a str number as an integer as content
 * 
 * @param number [in] String to be converted to integer and stored in node.
 * @return t_list A new node with an integer pointer as content.
 *
 * @note Returns NULL if number is not an integer or malloc failed.
 * @note Caller must free().
 * @warning 42 student
 */
static t_list	*ft_number_to_node(char *number)
{
	int		*integer;
	t_list	*node;

	if (!ft_isinteger(number))
		return (NULL);
	integer = malloc(sizeof(int));
	if (!integer)
		return (NULL);
	*integer = ft_atoi(number);
	node = ft_lstnew(integer);
	if (!node)
		free(integer);
	return (node);
}

/**
 * @brief Check for duplicates and valid integers
 * 
 * @param strs [in] Strings with potential duplicates.
 * @return int Returns 1 if any duplicate has been found, 0 if none.
 *
 * @warning 42 student
 */
static int	ft_is_valid_unique_integers(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		j = i + 1;
		while (strs[j])
		{
			if (!ft_isinteger(strs[i]) || !ft_isinteger(strs[j]))
				return (1);
			if (ft_atoi(strs[i]) == ft_atoi(strs[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief Create a t_list of str numbers passed to the program
 * 
 * @param argc [in] Correlates to length/index of arguments.
 * @param argv [in] Strings passed to program to make nodes of.
 * @return t_list The first node is the last argument passed.
 *
 * @note Last argument is the top of the stack!
 * @note  Arguments may only be of size int with no duplicates.
 * @note Frees and exits on error.
 * @warning 42 student
 */
static t_list	*ft_num_args_to_stack(int argc, char **argv)
{
	t_list	*new;
	t_list	*start;
	int		i;

	if (argc < 2)
		return (NULL);
	if (ft_is_valid_unique_integers(&argv[1]))
		ft_exit_on_error(NULL);
	i = 1;
	new = ft_number_to_node(argv[i++]);
	if (!new)
		ft_exit_on_error(new);
	start = new;
	while (i < argc)
	{
		new->next = ft_number_to_node(argv[i++]);
		if (!new->next)
			ft_exit_on_error(start);
		new = new->next;
	}
	ft_lstaddindex(start);
	return (start);
}

/**
 * @brief 42 Subject push_swap: Sort numbers using two stacks
 * 
 * @param argc [in] Correlates to length/index of arguments.
 * @param argv [in] Strings passed to program to make nodes of.
 * @return Returns 0 when program finished.
 * 
 * @warning 42 student
 */
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_cost	pick;

	a = ft_num_args_to_stack(argc, argv);
	if (!a)
		ft_exit_on_error(NULL);
	b = NULL;
	while (!ft_is_stack_ascend_circular(a))
	{
		ft_push_all_but_three(&a, &b);
		ft_sort_three(&a);
		while (b)
		{
			pick = ft_pick_lowest_cost(a, b);
			ft_sort_in_element(&a, &b, pick);
		}
	}
	ft_final_rot(&a);
	ft_lstclear(&a, free);
	return (0);
}
