/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzienert <jzienert@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:56:51 by jzienert          #+#    #+#             */
/*   Updated: 2025/08/07 13:31:53 by jzienert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

static size_t	ft_countwords(char const *s, char c)
{
	size_t	count;
	int		in_word;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else
		{
			if (in_word == 0)
				count++;
			in_word = 1;
		}
		s++;
	}
	return (count);
}

static void	*ft_freealloc(char **words, size_t wc)
{
	while (wc > 0)
	{
		free(words[wc - 1]);
		wc--;
	}
	free(words);
	return (NULL);
}

static char	**ft_wordinwords(char **words, const char *s, char c, size_t wc)
{
	size_t		i;
	const char	*start;

	wc = ft_countwords(s, c);
	i = 0;
	while (i < wc)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s != c && *s)
			s++;
		words[i] = malloc((s - start) + 1);
		if (!words[i])
			return (ft_freealloc(words, i));
		ft_strlcpy(words[i], start, s - start + 1);
		i++;
	}
	words[i] = NULL;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char		**words;
	size_t		wordcount;

	if (!s)
		return (NULL);
	wordcount = ft_countwords(s, c);
	words = malloc(sizeof(char *) * (wordcount + 1));
	if (!words)
		return (NULL);
	words = ft_wordinwords(words, s, c, wordcount);
	return (words);
}
