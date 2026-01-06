/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:19:40 by omghazi           #+#    #+#             */
/*   Updated: 2023/11/20 12:36:25 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_and_trim(char c, char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	size_t	start;
	size_t	end;
	size_t	current_index;

	if (!s1)
		return (NULL);
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && find_and_trim(s1[start], (char *)set) == 1)
		start++;
	while (end > start && find_and_trim(s1[end], (char *)set) == 1)
		end--;
	current_index = end - start + 1;
	arr = (char *)malloc(current_index + 1);
	if (!arr)
		return (NULL);
	ft_strlcpy(arr, s1 + start, current_index + 1);
	return (arr);
}
