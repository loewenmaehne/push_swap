/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:40:45 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:31:53 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

static char	*ft_itoa_strrev(char *s)
{
	char	*result;
	char	*temp;
	size_t	slen;
	size_t	sign;

	slen = ft_strlen(s);
	result = malloc(slen + 1);
	sign = 0;
	if (!result)
	{
		free(s);
		return (NULL);
	}
	temp = result;
	if (s[0] == '-')
	{
		*temp++ = '-';
		sign++;
	}
	while (slen > sign)
		*temp++ = s[slen-- - 1];
	*temp = '\0';
	free(s);
	return (result);
}

static char	*ft_malnumlen(long n)
{
	int		count;
	long	temp;
	char	*chrp;

	temp = n;
	count = 0;
	if (temp == 0 || temp < 0)
		count++;
	while (temp != 0)
	{
		temp = temp / 10;
		count++;
	}
	chrp = malloc(count + 1);
	if (!chrp)
		return (NULL);
	return (chrp);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nlong;
	char	*result;

	nlong = (long) n;
	str = ft_malnumlen(nlong);
	if (!str)
		return (NULL);
	result = str;
	if (nlong == 0)
		*str++ = '0';
	if (nlong < 0)
	{
		*str++ = '-';
		nlong = nlong * (-1);
	}
	while (nlong != 0)
	{
		*str++ = (nlong % 10) + '0';
		nlong = nlong / 10;
	}
	*str = '\0';
	return (ft_itoa_strrev(result));
}
