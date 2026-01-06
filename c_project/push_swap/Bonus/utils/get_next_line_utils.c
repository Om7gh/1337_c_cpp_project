/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 13:50:22 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/12 11:33:08 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

size_t	my_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && *(s + i))
		i++;
	return (i);
}

char	*my_strjoin(char *s1, char *s2, int n)
{
	int		i;
	int		j;
	char	*p;

	if (!s1 && s2)
		return (my_strdup(s2));
	if (!s2)
		return (free(s1), s1 = NULL, NULL);
	i = 0;
	j = 0;
	p = (char *)malloc((my_strlen(s1) + my_strlen(s2)) + 1);
	if (p == NULL)
		return (free(s1), s1 = NULL, NULL);
	while (s1[i] != '\0')
	{
		*(p + i) = s1[i];
		i++;
	}
	while (j < n)
	{
		*(p + i) = s2[j];
		j++;
		i++;
	}
	return (*(p + i) = '\0', free(s1), s1 = NULL, p);
}

char	*my_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (*(s + i) == (unsigned char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*my_strdup(char *str)
{
	char	*arr;
	int		i;

	i = 0;
	arr = (char *)malloc(my_strlen(str) + 1);
	if (!arr)
		return (NULL);
	while (*(str + i))
	{
		*(arr + i) = *(str + i);
		i++;
	}
	*(arr + i) = '\0';
	return (arr);
}

void	*my_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	total;
	size_t	i;

	total = count * size;
	if (count > 0 && SIZE_MAX / count < size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
