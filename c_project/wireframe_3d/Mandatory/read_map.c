/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:31:33 by omghazi           #+#    #+#             */
/*   Updated: 2024/02/11 03:02:46 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_map_height(t_map *map, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY, 0);
	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map->height++;
		free(line);
	}
	free(line);
	close(fd);
}

static void	get_map_width(t_map *map, char *file_name)
{
	int		fd;
	char	*line;
	char	**buff;
	int		i;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		terminate("invalid map !");
	}
	buff = ft_split(line, ' ');
	i = 0;
	while (buff[i])
	{
		free(buff[i]);
		map->width++;
		i++;
	}
	free(buff);
	free(line);
	close(fd);
}

void	fill_matrice(char **buff, t_map *map, char *line, int fd)
{
	int	i;
	int	j;

	i = 0;
	if (line && *line == '\n')
		terminate("invalide map !");
	while (i < map->height)
	{
		buff = ft_split(line, ' ');
		j = 0;
		while (buff[j] && j < map->width)
		{
			map->matrice_map[i][j] = ft_atoi(buff[j]);
			free(buff[j]);
			j++;
		}
		i++;
		free(buff[j]);
		free(buff);
		free(line);
		line = get_next_line(fd);
		if (line && *line == '\n')
			terminate("invalide map !");
	}
	free(line);
}

void	read_map(t_map *map, char *file_name)
{
	int		fd;
	char	*line;
	char	**buff;
	int		i;

	get_map_width(map, file_name);
	get_map_height(map, file_name);
	buff = NULL;
	map->matrice_map = malloc(sizeof(int *) * map->height);
	if (!map->matrice_map)
		free_memory(map);
	i = -1;
	while (++i < map->height)
	{
		map->matrice_map[i] = malloc(sizeof(int) * map->width);
		if (!map->matrice_map[i])
			free_memory(map);
	}
	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	i = 0;
	fill_matrice(buff, map, line, fd);
	close(fd);
}
