/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:04:06 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/16 05:34:24 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	put_pixel_to_img(int x, int y, int color, t_env *fdf)
{
	int	i;

	if (x > MENU_WIDTH && x < SCREEN_WIDTH && y > 0 && y < SCREEN_HEIGHT)
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
		if (i % SCREEN_WIDTH < MENU_WIDTH)
			img[i] = 0x34343a;
		else
			img[i] = 0x18171d;
		i += 1;
	}
}

void	bresenhams(t_vect start, t_vect end, t_env *fdf)
{
	t_vect	delta;
	t_vect	curr;
	int		err[2];

	delta.x = mod(start.x - end.x);
	delta.y = mod(start.y - end.y);
	curr = start;
	err[0] = delta.x - delta.y;
	while (curr.x != end.x || curr.y != end.y)
	{
		put_pixel_to_img(curr.x, curr.y, curr.color, fdf);
		err[1] = err[0] * 2;
		if (err[1] > -delta.y)
		{
			err[0] -= delta.y;
			curr.x += max(end.x, curr.x);
		}
		if (err[1] < delta.x)
		{
			err[0] += delta.x;
			curr.y += max(end.y, curr.y);
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
	ft_print_in_window(fdf);
}
