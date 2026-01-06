/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:25:14 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/17 03:08:19 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	get_ratio(int start, int end, int curr)
{
	double	placement;
	double	distance;

	placement = curr - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

void	free_exit(t_env *fdf)
{
	int	i;

	i = 0;
	while (i < fdf->map->height)
	{
		free(fdf->map->matrice_map[i]);
		i++;
	}
	free(fdf->map->matrice_map);
	free(fdf->map);
}
