/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:39:00 by afaris            #+#    #+#             */
/*   Updated: 2022/05/21 15:00:38 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	calculate_dimension(t_map *m)
{
	int		fd;
	char	*tmp;

	fd = open(m->filename, O_RDONLY);
	if (fd == -1)
		raise_error(0);
	tmp = get_next_line(fd);
	m->wall_width = len_count(tmp) - 1;
	free(tmp);
	m->wall_heigth = 1;
	tmp = get_next_line(fd);
	while (tmp)
	{
		m->wall_heigth++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	m->screen_height = BLOC_SIZE * m->wall_heigth;
	m->screen_width = BLOC_SIZE * m->wall_width;
	close(fd);
}

void	fill_map(t_map *m)
{
	int		fd;
	int		i;
	char	*tmp;

	i = 0;
	fd = open(m->filename, O_RDONLY);
	if (!fd)
		raise_error(0);
	m->map = malloc(sizeof(char *) * (m->wall_heigth + 1));
	tmp = get_next_line(fd);
	while (tmp)
	{
		m->map[i] = tmp;
		tmp = get_next_line(fd);
		i++;
	}
	m->map[i] = 0;
	close(fd);
}

t_map	get_map(char *filename)
{
	t_map	m;

	m.filename = end_with(filename, MAP_EXTENSION);
	calculate_dimension(&m);
	fill_map(&m);
	check_map_validity(m);
	return (m);
}
