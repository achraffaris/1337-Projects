/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:50:38 by afaris            #+#    #+#             */
/*   Updated: 2022/05/24 11:07:06 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus/so_long_bonus.h"

int	events_manager(int key, t_map *m)
{
	if (key == MOVE_UP)
		go_up(m);
	else if (key == MOVE_DOWN)
		go_down(m);
	else if (key == MOVE_LEFT)
		go_left(m);
	else if (key == MOVE_RIGHT)
		go_right(m);
	else if (key == KEY_ESC)
		happy_end(m);
	return (1);
}

void	map_init(t_map *m)
{
	m->clicks = 0;
	m->collectibles = 0;
	m->enemies = 0;
	m->player_index.i = 0;
	m->player_index.j = 0;
	m->player_pos.x = 0;
	m->player_pos.y = 0;
	m->i = 0;
	m->j = 0;
	img_init(m);
}

int	main(int ac, char **av)
{
	t_map	m;
	int		i;

	i = 0;
	if (ac != 2)
		return (0);
	m = get_map(av[1]);
	m.mlx = mlx_init();
	if (!m.mlx)
		raise_error("Unable to set up the connection to the graphical system!");
	m.mlx_win = mlx_new_window(m.mlx,
			m.screen_width, m.screen_height, "afaris");
	if (!m.mlx_win)
		raise_error("Unable to create a new window!");
	map_init(&m);
	render_all_images(&m);
	mlx_hook(m.mlx_win, KEY_PRESS, 0, events_manager, &m);
	mlx_hook(m.mlx_win, ON_DESTROY, 0, happy_end, &m);
	mlx_loop_hook(m.mlx, animate_it, &m);
	mlx_loop(m.mlx);
	free_2d(m.map);
}
