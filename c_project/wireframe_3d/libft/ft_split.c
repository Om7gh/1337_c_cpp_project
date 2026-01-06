/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:16:02 by omghazi           #+#    #+#             */
/*   Updated: 2023/11/12 13:54:57 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word_num(char const *s, char c)
{
	char	last;
	size_t	i;
	size_t	j;

	last = c;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (last == c && s[i] != c)
			j++;
		last = s[i];
		i++;
	}
	return (j);
}

static size_t	get_word_len(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i + j] && s[i + j] != c)
		j++;
	return (j);
}

static char	**ft_free(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	size_t			i;
	unsigned int	j;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	arr = (char **)malloc(sizeof(char *) * (get_word_num(s, c) + 1));
	if (!arr)
		return (NULL);
	while (++i < get_word_num(s, c))
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j])
		{
			arr[i] = ft_substr(s, j, get_word_len(&s[j], c));
			if (!arr[i])
				return (ft_free(arr, i));
			j += get_word_len(&s[j], c);
		}
	}
	arr[i] = NULL;
	return (arr);
}
