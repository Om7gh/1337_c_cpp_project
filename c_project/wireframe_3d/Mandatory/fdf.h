/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:32:57 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/17 03:05:45 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>

# define SHELL_RED "\033[0;31m"
# define SHELL_YELLOW "\033[0;33m"
# define SHELL_END_COLOR "\033[m"
# define TEXT_COLOR 0x1A1A1D
# define BACKGROUND 0x1A1A1D
# define MENU_BACKGROUND 0X34343A
# define ESC 53

# define BLACK 0x34343a
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

# define SCREEN_WIDTH 1500
# define SCREEN_HEIGHT 1000
# define MLX_ERROR 1
# define ANGLE M_PI

typedef struct s_vect
{
	int	x;
	int	y;
	int	z;
	int	color;
}			t_vect;

typedef enum s_projection
{
	ISO,
	PARALLEL
}			t_projection;

typedef struct s_mouse
{
	int	prev_x;
	int	prev_y;
	int	x;
	int	y;
	int	is_clicked;
}			t_mouse;

typedef struct s_map
{
	int				width;
	int				height;
	int				**matrice_map;
	int				zoom;
	int				z_divisor;
	int				x_offset;
	int				y_offset;
	int				z_min;
	int				z_max;
	t_projection	*projection;
}			t_map;

typedef struct s_env
{
	void				*run;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits;
	int					size_line;
	int					endian;
	t_map				*map;
	t_vect				*vect;
	t_mouse				*mouse;
}			t_env;

void		init_env(t_map *map, t_env *fdf, char *file_name);
t_map		*init_map(void);
void		read_map(t_map *map, char *file_name);
void		draw_line(t_env *fdf);
t_vect		projection(t_vect start, t_map *map);
t_vect		new_point(int x, int y, t_map *map);
void		terminate(char *s);
int			max(int a, int b);
int			mod(int a);
void		free_memory(t_map *map);
void		free_arr(char **arr);
int			handle_exit(t_env *fdf);
double		get_ratio(int start, int end, int curr);
int			listen_hook(int keyp, t_env *fdf);
void		free_exit(t_env *fdf);

#endif
