/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:04:18 by afaris            #+#    #+#             */
/*   Updated: 2022/05/21 14:43:51 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	display_score(t_map *m)
{
	ft_putnbr(m->clicks);
	write(1, "\n", 1);
}

int	game_over(t_map *m)
{
	free_2d(m->map);
	exit(0);
	return (0);
}
