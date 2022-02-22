/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:33:57 by afaris            #+#    #+#             */
/*   Updated: 2022/02/22 11:20:41 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_buffers(char **rest, char **line)
{
	if (rest)
	{
		free(*rest);
		*rest = 0;
	}
	if (line)
	{
		free(*line);
		*line = 0;
	}
}

int	get_length(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i] != c && str[i])
		i++;
	return (i);
}

char	*join_buffers(char *rest, char *line, char *buff)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * get_length(rest, 0)
			+ get_length(line, 0) + get_length(buff, 0) + 1);
	while (rest && rest[i])
		tmp[i++] = rest[j++];
	j = 0;
	while (line && line[j])
		tmp[i++] = line[j++];
	j = 0;
	while (buff && buff[j])
		tmp[i++] = buff[j++];
	tmp[i] = '\0';
	free_buffers(0, &line);
	return (tmp);
}

void	save_rest_st(char **rest, int pos)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = malloc(sizeof(char) * (get_length(&rest[0][pos], 0) + 1));
	while (*rest && rest[0][pos])
		tmp[i++] = rest[0][pos++];
	tmp[i] = '\0';
	free_buffers(&(*rest), 0);
	*rest = tmp;
}

void	save_rest(char **rest, char *buff, int pos)
{
	char	*tmp;
	int		i;

	i = 0;
	free_buffers(&(*rest), 0);
	tmp = malloc(sizeof(char) * (get_length(&buff[pos], 0) + 1));
	while (buff && buff[pos])
		tmp[i++] = buff[pos++];
	tmp[i] = '\0';
	*rest = tmp;
}
