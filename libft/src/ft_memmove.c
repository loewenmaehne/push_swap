/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:56:15 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:31:53 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destp;
	char	*srcp;
	size_t	i;

	i = 0;
	destp = (char *) dest;
	srcp = (char *) src;
	if (!dest && !src)
		return (NULL);
	if (destp > srcp && destp < srcp + n)
	{
		while (n-- > 0)
			destp[n] = srcp[n];
	}
	else
	{
		while (i < n)
		{
			destp[i] = srcp[i];
			i++;
		}
	}
	return (dest);
}
