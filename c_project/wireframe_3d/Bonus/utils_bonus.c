/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:52:20 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/10 16:35:00 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	terminate(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

int	max(int a, int b)
{
	if (a > b)
		return (1);
	return (-1);
}

int	mod(int a)
{
	if (a > 0)
		return (a);
	return (-a);
}

void	free_memory(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->matrice_map[i]);
		i++;
	}
	free(map->matrice_map);
}

void	free_arr(char **arr)
{
	int	size;

	size = 0;
	while (arr[size])
	{
		free(arr[size]);
		size++;
	}
}
