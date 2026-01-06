/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:25:14 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/09 02:25:09 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

double	get_ratio(int start, int end, int curr)
{
	double	distance;
	double	placement;

	placement = curr - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

void	ft_print_in_window(t_env *fdf)
{
	int	x;
	int	y;
	int	x_pos;
	int	y_pos;

	x = 10;
	y = 20;
	x_pos = MENU_WIDTH / x;
	y_pos = SCREEN_HEIGHT / y;
	mlx_string_put(fdf->run, fdf->win, x_pos
		+ 20, y_pos, COLOR_JAFFA, "MENU :");
	mlx_string_put(fdf->run, fdf->win, x_pos, y_pos
		+ 100, COLOR_JAFFA, "zoom :");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ 130, WHITE, "zoom_in +");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ 160, WHITE, "zoom_out -");
	ft_print_in_window_3(fdf, x_pos, y_pos);
	ft_print_in_window_2(fdf, x_pos, y_pos);
}

void	ft_print_in_window_2(t_env *fdf, int x_pos, int y_pos)
{
	mlx_string_put(fdf->run, fdf->win, x_pos, y_pos
		+ (SCREEN_HEIGHT / 2), COLOR_JAFFA, "rotate :");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT / 2 + 30), WHITE, "2 key");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT / 2 + 60), WHITE, "3 key");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT / 2 + 90), WHITE, "4 key");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT / 2 + 120), WHITE, "5 key");
	mlx_string_put(fdf->run, fdf->win, x_pos, y_pos
		+ (SCREEN_HEIGHT / 2 + 180), COLOR_JAFFA, "change projection :");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT / 2 + 210), WHITE, "isometry : 1");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT / 2 + 240), WHITE, "parallele : 0");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT - 100), WHITE, "made by omghazi");
}

void	ft_print_in_window_3(t_env *fdf, int x_pos, int y_pos)
{
	mlx_string_put(fdf->run, fdf->win, x_pos, y_pos
		+ (SCREEN_HEIGHT) / 3 - 120, COLOR_JAFFA, "Amplitude");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT) / 3 - 90, WHITE, "decress Z");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT) / 3 -60, WHITE, "incress X");
	mlx_string_put(fdf->run, fdf->win, x_pos, y_pos
		+ (SCREEN_HEIGHT / 3), COLOR_JAFFA, "translation :");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT / 3 + 30), WHITE, "left_arrow");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT / 3 + 60), WHITE, "right_arrow");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT / 3 + 90), WHITE, "top_arrow");
	mlx_string_put(fdf->run, fdf->win, x_pos + 20, y_pos
		+ (SCREEN_HEIGHT / 3 + 120), WHITE, "bottom_arrow");
}

void	change_projection(int *x, int *y, int *z)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*z = 1;
}
