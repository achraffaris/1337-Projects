/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 07:53:11 by afaris            #+#    #+#             */
/*   Updated: 2022/05/24 11:35:29 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	random_animation(t_map *m, int i)
{
	t_pos	p;

	p.x = m->enemies_list[i].x;
	p.y = m->enemies_list[i].y;
	mlx_put_image_to_window(m->mlx, m->mlx_win, m->enm_images.space, p.x, p.y);
	if (m->i == 4)
		mlx_put_image_to_window(m->mlx, m->mlx_win, m->enm_images.e1, p.x, p.y);
	else if (m->i == 3)
		mlx_put_image_to_window(m->mlx, m->mlx_win, m->enm_images.e2, p.x, p.y);
	else if (m->i == 2)
		mlx_put_image_to_window(m->mlx, m->mlx_win, m->enm_images.e3, p.x, p.y);
	else if (m->i == 1)
		mlx_put_image_to_window(m->mlx, m->mlx_win, m->enm_images.e4, p.x, p.y);
	else if (m->i == 0)
		mlx_put_image_to_window(m->mlx, m->mlx_win, m->enm_images.e5, p.x, p.y);
	m->i++;
	if (m->i == 5)
		m->i = 0;
}

int	animate_it(t_map *m)
{
	ft_delay(700);
	random_animation(m, m->j);
	m->j++;
	if (m->j >= m->enemies)
		m->j = 0;
	return (0);
}
