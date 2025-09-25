/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 13:24:04 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:31:53 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_atoi(const char *nptr)
{
	const char	*nptrs;
	int			atoi;
	int			sign;

	nptrs = nptr;
	atoi = 0;
	sign = 1;
	while (*nptrs == ' ' || (*nptrs >= 9 && *nptrs <= 13))
		nptrs++;
	if (*nptrs == '-')
	{
		sign = -1;
		nptrs++;
	}
	else if (*nptrs == '+')
		nptrs++;
	while (*nptrs >= '0' && *nptrs <= '9')
	{
		atoi = atoi * 10 + *nptrs - 48;
		nptrs++;
	}
	return (sign * atoi);
}
