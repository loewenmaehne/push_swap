/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 23:44:51 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:33:46 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/**
 * @brief Unsigned integer to ascii conversion
 * 
 * @param n [in] Unsigned integer number to convert to ascii.
 * @return char * Malloced number as string.
 *
 * @note Caller must free().
 * @warning 42 student
 * @see ft_printf_handle_u()
 */
char	*ft_uitoa(unsigned int n)
{
	char			*str;
	unsigned long	nlong;
	char			*result;

	nlong = (long) n;
	str = ft_malnumlen(nlong);
	if (!str)
		return (NULL);
	result = str;
	if (nlong == 0)
		*str++ = '0';
	while (nlong != 0)
	{
		*str++ = (nlong % 10) + '0';
		nlong = nlong / 10;
	}
	*str = '\0';
	return (ft_free_strrev(result));
}
