/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:08:59 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/21 18:12:15 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isnumber(char *s)
{
	if (!s || !*s)
		return (0);
	if (*s == '-')
		s++;
	while (ft_isdigit(*s))
		s++;
	return (!*s);
}

int	ft_isinteger(char *s)
{
	const char		int_max[10] = "2147483647";
	int				i;
	unsigned char	sign;
	size_t			len;

	if (!ft_isnumber(s))
		return (0);
	sign = 0;
	if (s[0] == '-')
		s = s + ++sign;
	len = ft_strlen(s);
	if (len < 10)
		return (1);
	if (len > 10)
		return (0);
	i = 0;
	while (i < 9)
	{
		if (s[i] > int_max[i])
			return (0);
		if (s[i] < int_max[i])
			return (1);
		i++;
	}
	return (s[i] <= int_max[i] + sign);
}
