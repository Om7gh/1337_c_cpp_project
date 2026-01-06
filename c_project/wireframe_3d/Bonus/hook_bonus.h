/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 08:47:41 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/17 03:48:09 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_BONUS_H
# define HOOK_BONUS_H

# include "fdf_bonus.h"

# define ESC 53
# define UP 13
# define RIGHT 2
# define LEFT 0
# define DOWN 1
# define ZOOM_IN 69
# define ZOOM_OUT 78
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_LEFT	1

int		listen_hook(int keyp, t_env *fdf);
int		handle_mouse(int button, int x, int y, t_env *fdf);
int		handle_exit(t_env *fdf);
int		rotate_map(int key, t_env *fdf);
int		handle_mouse(int button, int x, int y, t_env *fdf);
int		mouse_release(int button, int x, int y, t_env *fdf);
int		mouse_move(int x, int y, t_env *fdf);
void	free_exit(t_env *fdf);

#endif
