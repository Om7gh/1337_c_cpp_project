/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:14:53 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/17 03:07:26 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_exit(t_env *fdf)
{
	mlx_destroy_image(fdf->run, fdf->img);
	mlx_destroy_window(fdf->run, fdf->win);
	free_exit(fdf);
	exit(EXIT_SUCCESS);
}

void	destroy_window(t_env *fdf)
{
	mlx_destroy_image(fdf->run, fdf->img);
	mlx_destroy_window(fdf->run, fdf->win);
	free_exit(fdf);
	exit(EXIT_SUCCESS);
}

int	listen_hook(int keyp, t_env *fdf)
{
	if (keyp == ESC)
		destroy_window(fdf);
	return (keyp);
}
