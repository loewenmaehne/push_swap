/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:28:03 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/09 22:32:23 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Return the bigger of two ints
 * 
 * @param a [in] Integer to be compared against.
 * @param b [in] Integer to be compared against.
 * @return int Returns the bigger integer out of the two.
 *
 * @warning 42 student
 */
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
