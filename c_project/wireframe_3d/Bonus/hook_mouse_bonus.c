/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_mouse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:37:03 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/17 03:16:14 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "hook_bonus.h"

int	handle_exit(t_env *fdf)
{
	mlx_destroy_image(fdf->run, fdf->img);
	mlx_destroy_window(fdf->run, fdf->win);
	free_exit(fdf);
	exit(EXIT_SUCCESS);
}

int	handle_mouse(int button, int x, int y, t_env *fdf)
{
	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP)
		fdf->map->zoom += 1;
	else if (button == MOUSE_SCROLL_DOWN)
		fdf->map->zoom -= 1;
	else if (button == MOUSE_SCROLL_LEFT)
		fdf->mouse->is_clicked = 1;
	draw_line(fdf);
	return (0);
}

int	mouse_release(int button, int x, int y, t_env *fdf)
{
	(void)x;
	(void)y;
	(void)button;
	fdf->mouse->is_clicked = 0;
	return (0);
}

int	mouse_move(int x, int y, t_env *fdf)
{
	fdf->mouse->prev_x = fdf->mouse->x;
	fdf->mouse->prev_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_clicked && fdf->mouse->x >= 282)
	{
		fdf->map->angle->beta += (y - fdf->mouse->prev_y) * 0.002;
		fdf->map->angle->alpha += (x - fdf->mouse->prev_x) * 0.002;
		draw_line(fdf);
	}
	return (0);
}
