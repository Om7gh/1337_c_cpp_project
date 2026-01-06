/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 06:13:29 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/07 01:44:14 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x_axis(int *y, int *z)
{
	int	prev_y;

	prev_y = *y;
	*y = prev_y * cos(ANGLE) + *z * sin(ANGLE);
	*z = -prev_y * sin(ANGLE) + *z * cos(ANGLE);
}

void	rotate_y_axis(int *x, int *z)
{
	int	prev_x;

	prev_x = *x;
	*x = prev_x * cos(ANGLE) + *z * sin(ANGLE);
	*z = -prev_x * sin(ANGLE) + *z * cos(ANGLE);
}

void	rotate_z_axis(int *x, int *y)
{
	int	prev_y;
	int	prev_x;

	prev_y = *y;
	prev_x = *x;
	*x = prev_x * cos(ANGLE) - prev_y * sin(ANGLE);
	*y = prev_x * sin(ANGLE) + prev_y * cos(ANGLE);
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
	rotate_x_axis(&start.y, &start.z);
	rotate_y_axis(&start.x, &start.z);
	rotate_z_axis(&start.x, &start.y);
	isometry(&start.x, &start.y, start.z);
	start.x += SCREEN_WIDTH / 2 + map->x_offset;
	start.y += SCREEN_HEIGHT / 2 + map->y_offset;
	return (start);
}
