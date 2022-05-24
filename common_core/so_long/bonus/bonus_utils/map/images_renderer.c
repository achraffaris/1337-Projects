/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_renderer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:36:48 by afaris            #+#    #+#             */
/*   Updated: 2022/05/21 15:00:29 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	render_signle_image(char *path, void *mlx, void *mlx_win, t_pos p)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, p.x, p.y);
}

void	add_player(t_map *m, int i, int j, t_pos p)
{
	render_signle_image(PLAYER_UP_PATH, m->mlx, m->mlx_win, p);
	m->player_index.i = i;
	m->player_index.j = j;
	m->player_pos.x = p.x;
	m->player_pos.y = p.y;
}

void	add_collectibles(t_map *m, t_pos p)
{
	render_signle_image(COLLECTIBLE_PATH, m->mlx, m->mlx_win, p);
	m->collectibles++;
}

void	render_line_images(t_map *m, int i, int p_y)
{
	int		j;
	t_pos	p;

	j = 0;
	p.x = 0;
	p.y = p_y;
	while (m->map[i][j] && m->map[i][j] != '\n')
	{
		render_signle_image(SPACE_PATH, m->mlx, m->mlx_win, p);
		if (m->map[i][j] == WALL)
			render_signle_image(WALL_PATH, m->mlx, m->mlx_win, p);
		else if (m->map[i][j] == COLLECTIBLE)
			add_collectibles(m, p);
		else if (m->map[i][j] == EXIT)
			render_signle_image(EXIT_PATH, m->mlx, m->mlx_win, p);
		else if (m->map[i][j] == PLAYER)
			add_player(m, i, j, p);
		else if (m->map[i][j] == ENEMY)
		{
			m->enemies++;
			render_signle_image(ENEMY_PATH, m->mlx, m->mlx_win, p);
		}
		j++;
		p.x += BLOC_SIZE;
	}
}

void	render_all_images(t_map *m)
{
	t_pos	p;
	int		i;

	i = 0;
	p.y = 0;
	while (m->map[i] && i < m->wall_heigth)
	{
		render_line_images(m, i, p.y);
		p.y += BLOC_SIZE;
		i++;
	}
	display_score(m);
	m->enemies_list = get_enemies_positions(m);
}
