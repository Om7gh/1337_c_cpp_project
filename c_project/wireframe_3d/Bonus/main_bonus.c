/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:49:44 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/17 03:45:22 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "hook_bonus.h"

void	check_fd(char *file_name)
{
	int	fd ;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		terminate("invalid file please try again");
}

void	check_file_extension(char *file_name)
{
	char	*extention ;

	extention = ft_strrchr(file_name, '.');
	if (ft_strncmp(extention, ".fdf", 4) || ft_strlen(extention) != 4)
		terminate("invalide file extention please try again !");
	ft_putendl_fd("good file extension", 1);
}

int	main(int ac, char **av)
{
	t_env	fdf;
	t_map	*map;

	if (ac != 2)
		terminate("invalid argument please try again");
	check_fd(av[1]);
	map = init_map();
	init_env(map, &fdf, av[1]);
	check_file_extension(av[1]);
	read_map(map, av[1]);
	draw_line(&fdf);
	mlx_hook(fdf.win, 2, 1L << 0, listen_hook, &fdf);
	mlx_hook(fdf.win, 3, 1L << 0, rotate_map, &fdf);
	mlx_mouse_hook(fdf.win, handle_mouse, &fdf);
	mlx_hook(fdf.win, 17, 0, handle_exit, &fdf);
	mlx_hook(fdf.win, 4, 0, handle_mouse, &fdf);
	mlx_hook(fdf.win, 5, 0, mouse_release, &fdf);
	mlx_hook(fdf.win, 6, 0, mouse_move, &fdf);
	mlx_loop(fdf.run);
}
