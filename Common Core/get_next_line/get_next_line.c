/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:54:53 by afaris            #+#    #+#             */
/*   Updated: 2022/02/22 11:20:43 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*export_line_st(char **rest, int pos)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (pos + 2));
	while (*rest && i <= pos && rest[0][i])
	{
		tmp[i] = rest[0][i];
		i++;
	}
	tmp[i] = '\0';
	if (rest[0][i])
		save_rest_st(rest, pos + 1);
	else
		free_buffers(&(*rest), 0);
	return (tmp);
}

char	*export_line(char **rest, char *line, char *buff, int pos)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (get_length(*rest, 0)
				+ get_length(line, 0) + pos + 2));
	while (*rest && rest[0][i])
	{
		tmp[i] = rest[0][i];
		i++;
	}
	while (line && line[i])
	{
		tmp[i] = line[i];
		i++;
	}
	while (buff && j <= pos)
		tmp[i++] = buff[j++];
	tmp[i] = '\0';
	save_rest(rest, buff, pos + 1);
	free_buffers(0, &line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		buff[BUFFER_SIZE + 1];
	int			pos;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	pos = get_length(rest, '\n');
	if (rest && rest[pos] == '\n')
		return (export_line_st(&rest, pos));
	pos = read(fd, buff, BUFFER_SIZE);
	while (pos > 0)
	{
		buff[pos] = '\0';
		pos = get_length(buff, '\n');
		if (buff[pos] == '\n')
			return (export_line(&rest, line, buff, pos));
		line = join_buffers(rest, line, buff);
		pos = read(fd, buff, BUFFER_SIZE);
	}
	if (rest && !line && rest[0])
		line = join_buffers(rest, 0, 0);
	free_buffers(&rest, 0);
	return (line);
}
