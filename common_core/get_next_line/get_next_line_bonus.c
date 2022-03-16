/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:54:53 by afaris            #+#    #+#             */
/*   Updated: 2022/02/23 12:55:38 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*export_line_st(char **rest, int pos)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * (pos + 2));
	if (!tmp)
		return (0);
	while (*rest && i <= pos)
	{
		tmp[i] = (*rest)[i];
		i++;
	}
	tmp[i] = '\0';
	if ((*rest)[i])
		save_rest_st(&(*rest), i);
	else
		free_buffers(&(*rest));
	return (tmp);
}

char	*export_line(char **rest, char *buff, int pos)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (get_length(*rest, 0) + pos + 2));
	if (!tmp)
		return (0);
	while (*rest && (*rest)[i])
	{
		tmp[i] = (*rest)[i];
		i++;
	}
	while (buff && buff[j] && j <= pos)
		tmp[i++] = buff[j++];
	tmp[i] = '\0';
	free_buffers(&(*rest));
	if (buff[j])
		save_rest(&(*rest), buff, j);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		buff[BUFFER_SIZE + 1];
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	pos = get_length(rest[fd], '\n');
	if (rest[fd] && rest[fd][pos] == '\n')
		return (export_line_st(&rest[fd], pos));
	pos = read(fd, buff, BUFFER_SIZE);
	while (pos > 0)
	{
		buff[pos] = '\0';
		pos = get_length(buff, '\n');
		if (buff[pos] == '\n')
			return (export_line(&rest[fd], buff, pos));
		rest[fd] = join_buffers(&rest[fd], buff);
		pos = read(fd, buff, BUFFER_SIZE);
	}
	return (join_buffers(&rest[fd], 0));
}
