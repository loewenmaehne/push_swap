/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 09:26:25 by jzienert          #+#    #+#             */
/*   Updated: 2025/09/13 17:11:31 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	c1;

	c1 = (char) c;
	while (*s && *s != c1)
		s++;
	if (*s == c1)
		return ((char *) s);
	return (NULL);
}
