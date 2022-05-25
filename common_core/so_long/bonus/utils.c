/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 13:02:51 by afaris            #+#    #+#             */
/*   Updated: 2022/05/24 15:09:16 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	raise_error(char *err_msg, t_map *m)
{
	write(2, "Error\n", 7);
	if (!err_msg)
		perror(0);
	write(2, err_msg, len_count(err_msg));
	exit(1);
}

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free_arr(arr[i]);
			i++;
		}
		free(arr);
	}
}

void	free_arr(char *arr)
{
	if (arr)
	{
		free(arr);
		arr = NULL;
	}
}
