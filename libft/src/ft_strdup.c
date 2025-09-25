/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:36:10 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:31:53 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dupl;
	int		slen;

	slen = 0;
	while (s[slen] != '\0')
		slen++;
	dupl = malloc(slen + 1);
	if (!dupl)
		return (NULL);
	ft_strlcpy(dupl, s, slen + 1);
	return (dupl);
}
