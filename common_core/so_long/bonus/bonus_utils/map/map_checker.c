/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:42:37 by afaris            #+#    #+#             */
/*   Updated: 2022/05/24 15:08:41 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	rectangular_map(t_map m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m.map[i])
	{
		while (m.map[i][j] != '\n' && m.map[i][j])
		{
			if ((i == 0 || i == m.wall_heigth - 1) && (m.map[i][j] != WALL))
				return (0);
			else if ((j == 0 || j == m.wall_width - 1) && (m.map[i][j] != WALL))
				return (0);
			j++;
		}
		if (j != m.wall_width)
			return (0);
		if (m.map[m.wall_heigth - 1][m.wall_width] != '\0')
			return (0);
		i++;
		j = 0;
	}
	if (i != m.wall_heigth)
		return (0);
	return (1);
}

int	illegal_chars_exist(t_map m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m.map[i])
	{
		while (m.map[i][j] != '\n' && m.map[i][j])
		{
			if (!(m.map[i][j] == WALL
				|| m.map[i][j] == COLLECTIBLE ||
				m.map[i][j] == EXIT ||
				m.map[i][j] == SPACE ||
				m.map[i][j] == PLAYER ||
				m.map[i][j] == ENEMY))
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

void	check_map_validity(t_map m)
{
	if (illegal_chars_exist(m))
		raise_error("Illegal characters are found!\n");
	else if (!exists(m, PLAYER, 0))
		raise_error("Player is missing or duplicated\n");
	else if (!exists(m, COLLECTIBLE, 1))
		raise_error("Collectibles are missings!\n");
	else if (!exists(m, EXIT, 1))
		raise_error("Exits are missings!\n");
	else if (!rectangular_map(m))
		raise_error("Invalid map format!\n");
}
