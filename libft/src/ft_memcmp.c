/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:12:25 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:31:53 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cuscp;
	const unsigned char	*cuscp2;

	cuscp = (const unsigned char *)s1;
	cuscp2 = (const unsigned char *)s2;
	while (n-- != 0)
	{
		if (*cuscp != *cuscp2)
			return (*cuscp - *cuscp2);
		cuscp++;
		cuscp2++;
	}
	return (0);
}
