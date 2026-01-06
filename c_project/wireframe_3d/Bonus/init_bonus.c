/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:50:33 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/17 03:20:04 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_env(t_map *map, t_env *fdf, char *file_name)
{
	fdf->run = mlx_init();
	if (!fdf->run)
		terminate("can\'t start mlx");
	fdf->win = mlx_new_window(fdf->run, SCREEN_WIDTH, SCREEN_HEIGHT, file_name);
	if (!fdf->win)
		terminate("can\'t open the window");
	fdf->img = mlx_new_image(fdf->run, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!fdf->img)
		terminate("can\'t allocate image");
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits),
			&(fdf->size_line), &(fdf->endian));
	fdf->mouse = malloc(sizeof(t_mouse));
	if (!fdf->mouse)
		terminate("can\'t allocate mouse");
	fdf->vect = malloc(sizeof(t_vect));
	if (!fdf->vect)
		terminate("can\'t allocate vectors");
	fdf->mouse->is_clicked = 0;
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
	map->zoom = 10;
	map->height = 0;
	map->width = 0;
	map->projection = ISO;
	map->z_divisor = 1;
	map->angle = malloc(sizeof(t_angle));
	if (!map->angle)
		terminate("can\'t allocate memory try again !");
	map->angle->alpha = M_PI;
	map->angle->beta = M_PI;
	map->angle->gamma = M_PI;
	return (map);
}
