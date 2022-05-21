/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:16:44 by afaris            #+#    #+#             */
/*   Updated: 2022/05/21 14:59:18 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../so_long.h"

# define ENEMY_PATH "assets/enemy.xpm"
# define ENEMY_PATH_2 "assets/enemy_animation/2.xpm"
# define ENEMY_PATH_3 "assets/enemy_animation/3.xpm"
# define ENEMY_PATH_4 "assets/enemy_animation/4.xpm"
# define ENEMY_PATH_5 "assets/enemy_animation/5.xpm"
# define ENEMY_PATH_6 "assets/enemy_animation/6.xpm"

int		animate_it(t_map *m);
void	ft_delay(double sec);
t_pos	*get_enemies_positions(t_map *m);

#endif