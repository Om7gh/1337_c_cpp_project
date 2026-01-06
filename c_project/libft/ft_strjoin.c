/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:55:56 by omghazi           #+#    #+#             */
/*   Updated: 2023/11/17 00:31:42 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	size_t	index;
	size_t	jndex;

	if (!s1 || !s2)
		return (NULL);
	arr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!arr)
		return (NULL);
	index = 0;
	jndex = 0;
	while (s1[index])
	{
		arr[index] = s1[index];
		index++;
	}
	while (s2[jndex])
	{
		arr[index + jndex] = s2[jndex];
		jndex++;
	}
	arr[index + jndex] = 0;
	return (arr);
}
