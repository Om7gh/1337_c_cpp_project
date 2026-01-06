/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 02:41:54 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/14 15:14:26 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap_bonus.h"

static unsigned int	count_word(char *s)
{
	char	last;
	int		i;
	int		words;

	i = 0;
	last = ' ';
	words = 0;
	while (s[i])
	{
		if (last == ' ' && (s[i] != ' ' && s[i] != '\t'))
			words++;
		last = s[i];
		i++;
	}
	return (words);
}

static unsigned int	word_len(char *s)
{
	int	len;

	len = 0;
	while (s[len] && (s[len] != ' ' && s[len] != '\t'))
		len++;
	return (len);
}

static char	*str_copy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) && (s1[i] != ' ' && s1[i] != '\t'))
	{
		*(s2 + i) = *(s1 + i);
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}

void	fill_matrice(char *s, char **new, int *i, int *j)
{
	while (s[*i])
	{
		while (s[*i] <= 32)
			(*i)++;
		if (s[*i])
		{
			new[*j] = malloc(sizeof(char) * (word_len(s + *i) + 1));
			if (!new[*j])
				(free_2d(new, *i), error());
			new[*j] = str_copy(s + *i, new[*j]);
			(*j)++;
		}
		while (s[*i] && (s[*i] != ' ' && s[*i] != '\t'))
			(*i)++;
	}
}

char	**ft_split(char *s)
{
	int		i;
	int		j;
	char	**new;

	i = 0;
	j = 0;
	new = malloc(sizeof(char *) * (count_word(s) + 1));
	if (!new)
		error();
	fill_matrice(s, new, &i, &j);
	return (new[j] = NULL, new);
}
