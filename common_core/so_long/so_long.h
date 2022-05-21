/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:16:44 by afaris            #+#    #+#             */
/*   Updated: 2022/05/21 14:57:15 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAP_EXTENSION ".ber"

# define PLAYER 'P'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define SPACE '0'
# define ENEMY 'G'

# define BLOC_SIZE 36
# define ON_DESTROY 17
# define KEY_PRESS 2
# define MOVE_UP 13
# define MOVE_DOWN 1
# define MOVE_LEFT 0
# define MOVE_RIGHT 2
# define TXT_BLOC_SIZE 4
# define KEY_ESC 53

# define SPACE_PATH "assets/space.xpm"
# define WALL_PATH "assets/wall.xpm"
# define EXIT_PATH "assets/door.xpm"
# define COLLECTIBLE_PATH "assets/collectible.xpm"
# define PLAYER_UP_PATH "assets/player_up.xpm"
# define PLAYER_DOWN_PATH "assets/player_down.xpm"
# define PLAYER_RIGHT_PATH "assets/player_right.xpm"
# define PLAYER_LEFT_PATH "assets/player_left.xpm"

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct index
{
	int	i;
	int	j;
}	t_index;

typedef struct var
{
	int	i;
	int	j;
	int	k;
}	t_var;

typedef struct map
{
	char	**map;
	int		wall_width;
	int		wall_heigth;
	int		screen_width;
	int		screen_height;
	int		collectibles;
	int		enemies;
	void	*mlx;
	void	*mlx_win;
	int		clicks;
	t_index	player_index;
	t_pos	player_pos;
	t_pos	*enemies_list;
	char	*filename;
	int		i;

}	t_map;

void	raise_error(char *err_msg);
char	*get_next_line(int fd);
int		len_count(char *str);
char	*end_with(char *str, char *end);
t_map	get_map(char *filename);
int		exists(t_map m, char c, int many);
int		rectangular_map(t_map m);
int		illegal_chars_exist(t_map m);
void	ft_putnbr(int n);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
void	go_up(t_map *m);
void	go_down(t_map *m);
void	go_left(t_map *m);
void	go_right(t_map *m);
void	display_score(t_map *m);
void	put_img(char *path, void *mlx, void *mlx_win, t_pos p);
void	put_images(t_map *m);
int		game_over(t_map *m);
void	free_2d(char **arr);
void	free_arr(char *arr);
void	check_map_validity(t_map m);
void	render_all_images(t_map *m);
void	render_signle_image(char *path, void *mlx, void *mlx_win, t_pos p);

#endif