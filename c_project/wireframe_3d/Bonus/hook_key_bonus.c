/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:29:48 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/17 03:43:41 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook_bonus.h"
#include "fdf_bonus.h"

void	destroy_window(t_env *fdf)
{
	mlx_destroy_window(fdf->run, fdf->win);
	mlx_destroy_image(fdf->run, fdf->img);
	free_exit(fdf);
	exit(EXIT_SUCCESS);
}

void	translation(int key, t_env *fdf)
{
	if (key == UP || key == 126)
	{
		fdf->map->y_offset -= 2;
		if (fdf->map->y_offset == -170)
			fdf->map->y_offset = 0;
	}
	else if (key == DOWN || key == 125)
	{
		fdf->map->y_offset += 2;
		if (fdf->map->y_offset == 200)
			fdf->map->y_offset = 0;
	}
	else if (key == LEFT || key == 123)
	{
		fdf->map->x_offset -= 2;
		if (fdf->map->x_offset == -370)
			fdf->map->x_offset = 0;
	}
	else if (key == RIGHT || key == 124)
	{
		fdf->map->x_offset += 2;
		if (fdf->map->x_offset == 350)
			fdf->map->x_offset = 0;
	}
}

void	zoom_in_out(int key, t_env *fdf)
{
	if (key == ZOOM_IN)
		fdf->map->zoom++;
	if (key == ZOOM_OUT)
		fdf->map->zoom--;
}

void	change_amplitude(int key, t_env *fdf)
{
	if (key == 6)
		(fdf->map->z_divisor) += 2;
	if (key == 7)
		fdf->map->z_divisor -= 2;
}

int	listen_hook(int keyp, t_env *fdf)
{
	if (keyp == ESC)
		destroy_window(fdf);
	if (keyp == UP || keyp == DOWN || keyp == LEFT || keyp == RIGHT
		|| keyp == 125 || keyp == 126 || keyp == 123 || keyp == 124)
		translation(keyp, fdf);
	if ((keyp == ZOOM_IN || keyp == ZOOM_OUT))
		zoom_in_out(keyp, fdf);
	if (keyp == 6 || keyp == 7)
		change_amplitude(keyp, fdf);
	if (keyp == 82)
		fdf->map->projection = PARALLEL;
	else if (keyp == 83)
		fdf->map->projection = ISO;
	draw_line(fdf);
	return (keyp);
}
