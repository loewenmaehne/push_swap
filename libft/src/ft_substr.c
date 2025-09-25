/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:54:23 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:31:53 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	slen;
	size_t	remlen;

	if (!s)
		return (NULL);
	slen = (size_t) ft_strlen(s);
	if (slen <= start)
		return (ft_strdup(""));
	remlen = slen - start;
	if (remlen > len)
		remlen = len;
	subs = malloc(remlen + 1);
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, (s + start), (remlen + 1));
	return (subs);
}
