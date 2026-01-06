/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 01:47:03 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/11 03:29:13 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	rotate_x_axis(int *y, int *z, t_map *map)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(map->angle->alpha) + *z * sin(map->angle->alpha);
	*z = -prev_y * sin(map->angle->alpha) + *z * cos(map->angle->alpha);
}

void	rotate_y_axis(int *x, int *z, t_map *map)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(map->angle->beta) + *z * sin(map->angle->beta);
	*z = -prev_x * sin(map->angle->beta) + *z * cos(map->angle->beta);
}

void	rotate_z_axis(int *x, int *y, t_map *map)
{
	int	prev_y;
	int	prev_x;

	prev_y = *y;
	prev_x = *x;
	*x = prev_x * cos(map->angle->gamma) - prev_y * sin(map->angle->gamma);
	*y = prev_x * sin(map->angle->gamma) + prev_y * cos(map->angle->gamma);
}

void	isometry(int *x, int *y, int z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = (prev_x + prev_y) * sin(0.523599) - z;
}

t_vect	projection(t_vect start, t_map *map)
{
	start.x *= map->zoom;
	start.y *= map->zoom;
	start.z *= map->zoom / map->z_divisor;
	start.x -= (map->width * map->zoom) / 2;
	start.y -= (map->height * map->zoom) / 2;
	rotate_x_axis(&start.y, &start.z, map);
	rotate_y_axis(&start.x, &start.z, map);
	rotate_z_axis(&start.x, &start.y, map);
	if (map->projection == ISO)
		isometry(&start.x, &start.y, start.z);
	else
		change_projection(&start.x, &start.y, &start.z);
	start.x += (SCREEN_WIDTH - MENU_WIDTH) / 2 + map->x_offset + MENU_WIDTH;
	start.y += SCREEN_HEIGHT / 2 + map->y_offset;
	return (start);
}
