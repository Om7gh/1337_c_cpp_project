/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omghazi <omghazi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:35:54 by omghazi           #+#    #+#             */
/*   Updated: 2024/04/12 11:32:11 by omghazi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/get_next_line.h"

static char	*read_line(int fd, char *buff)
{
	int		byte;
	char	*buffer;

	buffer = (char *)my_calloc(BUFFER_SIZE + 1, 1);
	if (!buffer)
		return (free(buff), buff = NULL, NULL);
	byte = 1;
	while (byte > 0 && !my_strchr(buff, '\n'))
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
			return (free(buff), free(buffer), buff = NULL, buffer = NULL, NULL);
		if (byte > 0)
			buff = my_strjoin(buff, buffer, byte);
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
	i = my_strlen(line);
	new_len = my_strlen(buff) - i;
	arr = (char *)my_calloc(new_len + 1, 1);
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
	static char	*container;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE < 0)
	{
		free(container);
		container = NULL;
		return (NULL);
	}
	container = read_line(fd, container);
	line = get_line(container);
	container = update(container, line);
	if (!line || !*line)
		return (free(line), free(container),
			container = NULL, line = NULL, NULL);
	return (line);
}
