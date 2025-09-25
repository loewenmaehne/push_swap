/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:27:52 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/10 13:30:21 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/**
 * @brief Return the smaller of two ints
 * 
 * @param a [in] Integer to be compared against.
 * @param b [in] Integer to be compared against.
 * @return int Returns the smaller integer out of the two.
 *
 * @warning 42 student
 */
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
