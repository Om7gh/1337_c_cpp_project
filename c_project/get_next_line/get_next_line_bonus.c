/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:35:54 by omghazi           #+#    #+#             */
/*   Updated: 2023/12/13 13:51:23 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd, char *buff)
{
	int		byte;
	char	*buffer;

	buffer = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (free(buff), buff = NULL, NULL);
	byte = 1;
	while (byte > 0 && !ft_strchr(buff, '\n'))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (free(buff), free(buffer), buff = NULL, buffer = NULL, NULL);
		if (byte > 0)
			buff = ft_strjoin(buff, buffer, byte);
		if (!buff)
			return (free(buffer), buffer = NULL, NULL);
	}
	free(buffer);
	buffer = NULL;
	return (buff);
}

static char	*get_line(char *buff)
{
	char	*ret_line;
	int		i;
	int		j;

	if (!buff)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	j = 0;
	ret_line = (char *)malloc(i + 1);
	if (!ret_line)
		return (NULL);
	while (j < i)
	{
		ret_line[j] = buff[j];
		j++;
	}
	return (ret_line[j] = '\0', ret_line);
}

static char	*update(char *buff, char *line)
{
	char	*arr;
	int		i;
	int		new_len;

	if (!buff || !line)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	i = ft_strlen(line);
	new_len = ft_strlen(buff) - i;
	arr = (char *)ft_calloc(new_len + 1, 1);
	if (!arr)
		return (free(buff), buff = NULL, NULL);
	while (new_len >= 0)
	{
		*(arr + new_len) = *(buff + new_len + i);
		new_len--;
	}
	free(buff);
	buff = NULL;
	return (arr);
}

char	*get_next_line(int fd)
{
	static char	*container[OPEN_MAX];
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE < 0)
	{
		free(container[fd]);
		container[fd] = NULL;
		return (NULL);
	}
	container[fd] = read_line(fd, container[fd]);
	line = get_line(container[fd]);
	container[fd] = update(container[fd], line);
	if (!line || !*line)
		return (free(line), free(container[fd]),
			container[fd] = NULL, line = NULL, NULL);
	return (line);
}
