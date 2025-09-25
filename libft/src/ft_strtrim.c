/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:02:32 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:31:53 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

static char	*ft_memstrempty(void)
{
	char	*p;

	p = malloc(1);
	if (!p)
		return (NULL);
	*p = '\0';
	return (p);
}

static size_t	ft_stroccsetend(char const *s1, char const *set)
{
	int	i;
	int	strlen;

	strlen = ft_strlen(s1);
	i = strlen - 1;
	while (i >= 0 && ft_strrchr(set, s1[i]))
		i--;
	return (strlen -1 - i);
}

static size_t	ft_stroccsetstart(char const *s1, char const *set)
{
	size_t	i;
	size_t	occ;

	occ = 0;
	while (*s1 != '\0')
	{
		i = 0;
		while (*s1 != set[i] && set[i] != '\0')
			i++;
		if (*s1 == set[i])
			occ++;
		else
			return (occ);
		s1++;
	}
	return (occ);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	strlen;
	char	*dup;

	if (!s1 || !set)
		return (ft_memstrempty());
	strlen = ft_strlen(s1);
	if (strlen == 0)
		return (ft_memstrempty());
	if ((ft_strlen(set) == 0))
		return (ft_strdup(s1));
	start = ft_stroccsetstart(s1, set);
	end = strlen - ft_stroccsetend(s1, set);
	if (start >= end)
		return (ft_memstrempty());
	dup = malloc(end - start + 1);
	if (!dup)
		return (NULL);
	ft_memmove(dup, s1 + start, end - start);
	dup[end - start] = '\0';
	return (dup);
}
