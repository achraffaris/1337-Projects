/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:57:16 by afaris            #+#    #+#             */
/*   Updated: 2022/05/21 15:00:24 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	var_init(t_var *v, t_pos *tmp)
{
	v->i = 0;
	v->j = 0;
	v->k = 0;
	tmp->x = 0;
	tmp->y = 0;
}

void	var_next(t_var *v, t_pos *tmp)
{
	v->i++;
	tmp->x = 0;
	tmp->y += BLOC_SIZE;
	v->j = 0;
}

t_pos	*get_enemies_positions(t_map *m)
{
	t_pos	*p;
	t_pos	t;
	t_var	v;

	p = malloc(sizeof(t_pos) * m->enemies);
	var_init(&v, &t);
	while (m->map[v.i] && v.i < m->wall_heigth)
	{
		while (m->map[v.i][v.j] && m->map[v.i][v.j] != '\n')
		{
			if (m->map[v.i][v.j] == ENEMY)
			{
				p[v.k].x = t.x;
				p[v.k].y = t.y;
				v.k++;
			}
			t.x += BLOC_SIZE;
			v.j++;
		}
		var_next(&v, &t);
	}
	return (p);
}

void	ft_delay(double sec)
{
	int	c;
	int	d;

	c = 1;
	d = 1;
	while (c <= sec * 20000)
	{
		while (d <= 36521)
			d++;
		c++;
	}
}
