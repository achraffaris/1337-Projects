/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:38:58 by afaris            #+#    #+#             */
/*   Updated: 2022/04/17 15:41:32 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

int	valid_file(char *filename, t_var *v)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		v->i++;
		v->pos++;
		perror(filename);
	}
	return (fd);
}
