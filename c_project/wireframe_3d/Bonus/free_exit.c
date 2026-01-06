/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 03:09:26 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/17 03:45:50 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "hook_bonus.h"

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
	free(fdf->map->angle);
	free(fdf->map);
	free(fdf->vect);
	free(fdf->mouse);
}
