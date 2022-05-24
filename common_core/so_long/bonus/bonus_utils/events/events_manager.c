/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:04:18 by afaris            #+#    #+#             */
/*   Updated: 2022/05/24 11:51:52 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	display_score(t_map *m)
{
	char	*score;
	int		i;
	t_pos	p;

	i = TXT_BLOC_SIZE;
	score = ft_strjoin("Score: ", ft_itoa(m->clicks));
	p.x = m->screen_width - (TXT_BLOC_SIZE * BLOC_SIZE);
	p.y = 0;
	while (i > 0)
	{
		render_signle_image(WALL_PATH, m->mlx, m->mlx_win, p);
		i--;
		p.x += BLOC_SIZE;
	}
	mlx_string_put(m->mlx, m->mlx_win,
		m->screen_width - (TXT_BLOC_SIZE * BLOC_SIZE), 0, 0xFFFFFF, score);
	ft_putnbr(m->clicks);
	write(1, "\n", 1);
	free_arr(score);
}

int	game_over(t_map *m)
{
	free_2d(m->map);
	write(1, "Game over :( ... Try Again!\n", 29);
	exit(0);
	return (0);
}

int	happy_end(t_map *m)
{
	write(1, "Thanks for playing, Hope you enjoyed!\n", 39);
	free_2d(m->map);
	exit(0);
	return (0);
}
