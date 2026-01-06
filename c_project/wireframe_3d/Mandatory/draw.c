/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:04:06 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/11 19:17:45 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel_to_img(int x, int y, int color, t_env *fdf)
{
	int	i;

	if (x > 0 && x < SCREEN_WIDTH && y > 0 && y < SCREEN_HEIGHT)
	{
		i = (x * fdf->bits / 8) + (y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

void	draw_bg_img(t_env *fdf)
{
	int	*img;
	int	i;

	ft_bzero(fdf->data_addr, SCREEN_HEIGHT * SCREEN_WIDTH * fdf->bits / 8);
	img = (int *)fdf->data_addr;
	i = 0;
	while (i < SCREEN_HEIGHT * SCREEN_WIDTH)
	{
		img[i] = BLACK;
		i += 1;
	}
}

void	bresenhams(t_vect start, t_vect end, t_env *fdf)
{
	int	dx ;
	int	dy ;
	int	err;
	int	err2;

	dx = mod(end.x - start.x);
	dy = mod(end.y - start.y);
	err = dx - dy;
	while (1)
	{
		put_pixel_to_img(start.x, start.y, start.color, fdf);
		if (start.x == end.x && start.y == end.y)
			break ;
		err2 = err * 2;
		if (err2 > -dy)
		{
			err -= dy;
			start.x += max(end.x, start.x);
		}
		if (err2 < dx)
		{
			err += dx;
			start.y += max(end.y, start.y);
		}
	}
}

t_vect	new_point(int x, int y, t_map *map)
{
	t_vect	p;

	p.x = x;
	p.y = y;
	p.z = map->matrice_map[y][x];
	if (map->matrice_map[y][x] == 0)
		p.color = WHITE;
	else
		p.color = COLOR_JAFFA;
	return (p);
}

void	draw_line(t_env *fdf)
{
	int			x;
	int			y;

	y = -1;
	draw_bg_img(fdf);
	while (++y < fdf->map->height)
	{
		x = -1;
		while (++x < fdf->map->width)
		{
			if (x < fdf->map->width - 1)
				bresenhams(projection(new_point(x, y, fdf->map), fdf->map),
					projection(new_point(x + 1, y, fdf->map),
						fdf->map), fdf);
			if (y < fdf->map->height - 1)
				bresenhams(projection(new_point(x, y, fdf->map), fdf->map),
					projection(new_point(x, y + 1, fdf->map),
						fdf->map), fdf);
		}
	}
	mlx_put_image_to_window(fdf->run, fdf->win, fdf->img, 0, 0);
}
