/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:12:01 by afaris            #+#    #+#             */
/*   Updated: 2022/04/07 12:19:14 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_UTILS_H
# define FREE_UTILS_H

# include "../utils.h"

void	free_2d_array(char **arr);
void	free_array(char *arr);
void	free_cmdinfo(t_cmdinfo *ci);

#endif