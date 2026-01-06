/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 03:21:13 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/13 14:26:26 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	error(void)
{
	ft_putendl("Error");
	exit(1);
}

int	is_overflow(long n)
{
	if (n > INT_MAX)
		return (1);
	else if (n < INT_MIN)
		return (1);
	return (0);
}

void	free_2d(char **new, int i)
{
	int	size;

	size = 0;
	while (size <= i)
	{
		free(new[size]);
		size++;
	}
	free(new);
	new = NULL;
}

void	ft_swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	is_space(char c)
{
	return (c == 32 || c == '\t');
}
