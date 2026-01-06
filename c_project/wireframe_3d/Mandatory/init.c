/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:50:33 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/10 15:16:28 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_env(t_map *map, t_env *fdf, char *file_name)
{
	fdf->run = mlx_init();
	if (!fdf->run)
		terminate("can\'t start mlx");
	fdf->win = mlx_new_window(fdf->run, SCREEN_WIDTH, SCREEN_HEIGHT, file_name);
	if (!fdf->win)
		terminate("can\'t open the window");
	fdf->img = mlx_new_image(fdf->run, SCREEN_WIDTH, SCREEN_HEIGHT);
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits),
			&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
}

t_map	*init_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		terminate("can\'t allocate map");
	map->matrice_map = NULL;
	map->x_offset = 0;
	map->y_offset = 0;
	map->zoom = 20;
	map->height = 0;
	map->width = 0;
	map->z_divisor = 1;
	return (map);
}
