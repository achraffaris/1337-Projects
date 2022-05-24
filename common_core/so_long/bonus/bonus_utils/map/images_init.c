/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:37:50 by afaris            #+#    #+#             */
/*   Updated: 2022/05/24 11:51:21 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	img_init(t_map *m)
{
	int	img_width;
	int	img_height;

	m->enm_images.e1 = mlx_xpm_file_to_image(m->mlx,
			ENEMY_PATH, &img_width, &img_height);
	m->enm_images.e2 = mlx_xpm_file_to_image(m->mlx,
			ENEMY_PATH_2, &img_width, &img_height);
	m->enm_images.e3 = mlx_xpm_file_to_image(m->mlx, ENEMY_PATH_3,
			&img_width, &img_height);
	m->enm_images.e4 = mlx_xpm_file_to_image(m->mlx, ENEMY_PATH_4,
			&img_width, &img_height);
	m->enm_images.e5 = mlx_xpm_file_to_image(m->mlx, ENEMY_PATH_5,
			&img_width, &img_height);
	m->enm_images.space = mlx_xpm_file_to_image(m->mlx, SPACE_PATH,
			&img_width, &img_height);
}
