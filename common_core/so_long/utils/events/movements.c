/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:06:31 by afaris            #+#    #+#             */
/*   Updated: 2022/05/21 14:44:59 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	go_up(t_map *m)
{
	char	target;

	target = m->map[m->player_index.i - 1][m->player_index.j];
	if (target == EXIT && m->collectibles <= 0)
		game_over(m);
	else if (target == COLLECTIBLE && m->collectibles > 0)
	{
		m->collectibles--;
		m->map[m->player_index.i - 1][m->player_index.j] = SPACE;
	}
	if (target != EXIT && target != WALL)
	{
		render_signle_image(SPACE_PATH, m->mlx, m->mlx_win, m->player_pos);
		m->player_pos.y -= BLOC_SIZE;
		m->player_index.i--;
		render_signle_image(PLAYER_UP_PATH, m->mlx, m->mlx_win, m->player_pos);
		m->clicks++;
		display_score(m);
	}
}

void	go_down(t_map *m)
{
	char	target;

	target = m->map[m->player_index.i + 1][m->player_index.j];
	if (target == EXIT && m->collectibles <= 0)
		game_over(m);
	else if (target == COLLECTIBLE && m->collectibles > 0)
	{
		m->collectibles--;
		m->map[m->player_index.i + 1][m->player_index.j] = SPACE;
	}
	if (target != EXIT && target != WALL)
	{
		render_signle_image(SPACE_PATH, m->mlx, m->mlx_win, m->player_pos);
		m->player_pos.y += BLOC_SIZE;
		m->player_index.i++;
		render_signle_image(PLAYER_DOWN_PATH,
			m->mlx, m->mlx_win, m->player_pos);
		m->clicks++;
		display_score(m);
	}
}

void	go_left(t_map *m)
{
	char	target;

	target = m->map[m->player_index.i][m->player_index.j - 1];
	if (target == EXIT && m->collectibles <= 0)
		game_over(m);
	else if (target == COLLECTIBLE && m->collectibles > 0)
	{
		m->collectibles--;
		m->map[m->player_index.i][m->player_index.j - 1] = SPACE;
	}
	if (target != EXIT && target != WALL)
	{
		render_signle_image(SPACE_PATH, m->mlx, m->mlx_win, m->player_pos);
		m->player_pos.x -= BLOC_SIZE;
		m->player_index.j--;
		render_signle_image(PLAYER_LEFT_PATH, m->mlx,
			m->mlx_win, m->player_pos);
		m->clicks++;
		display_score(m);
	}
}

void	go_right(t_map *m)
{
	char	target;

	target = m->map[m->player_index.i][m->player_index.j + 1];
	if (target == EXIT && m->collectibles <= 0)
		game_over(m);
	else if (target == COLLECTIBLE && m->collectibles > 0)
	{
		m->collectibles--;
		m->map[m->player_index.i][m->player_index.j + 1] = SPACE;
	}
	if (target != EXIT && target != WALL)
	{
		render_signle_image(SPACE_PATH, m->mlx, m->mlx_win, m->player_pos);
		m->player_pos.x += BLOC_SIZE;
		m->player_index.j++;
		render_signle_image(PLAYER_RIGHT_PATH,
			m->mlx, m->mlx_win, m->player_pos);
		m->clicks++;
		display_score(m);
	}
}
