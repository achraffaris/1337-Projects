/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 07:53:11 by afaris            #+#    #+#             */
/*   Updated: 2022/05/21 15:00:12 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	random_animation(t_map *m, int i)
{
	t_pos	p;

	p.x = m->enemies_list[i].x;
	p.y = m->enemies_list[i].y;
	render_signle_image(SPACE_PATH, m->mlx, m->mlx_win, p);
	if (m->i == 4)
		render_signle_image(ENEMY_PATH, m->mlx, m->mlx_win, p);
	else if (m->i == 3)
		render_signle_image(ENEMY_PATH_2, m->mlx, m->mlx_win, p);
	else if (m->i == 2)
		render_signle_image(ENEMY_PATH_3, m->mlx, m->mlx_win, p);
	else if (m->i == 1)
		render_signle_image(ENEMY_PATH_4, m->mlx, m->mlx_win, p);
	else if (m->i == 0)
		render_signle_image(ENEMY_PATH_5, m->mlx, m->mlx_win, p);
	m->i++;
	if (m->i == 5)
		m->i = 0;
}

int	animate_it(t_map *m)
{
	int	i;

	i = 0;
	ft_delay(0.055);
	while (i < m->enemies)
	{
		random_animation(m, i);
		i++;
	}
	return (0);
}
