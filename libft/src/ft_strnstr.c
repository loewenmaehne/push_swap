/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:08:02 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:31:53 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	llen;
	size_t	i;

	if (!*little)
		return ((char *) big);
	llen = ft_strlen(little);
	i = 0;
	while (big[i] && i + llen <= n)
	{
		if (ft_strncmp(&big[i], little, llen) == 0)
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
