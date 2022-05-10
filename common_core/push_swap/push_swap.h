/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:47:50 by afaris            #+#    #+#             */
/*   Updated: 2022/05/10 13:49:16 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN 2147483648

#include <stdlib.h>
#include <unistd.h>


int     ft_strcmp(const char *s1, const char *s2);
void    raise_error();
int     *clean_data(char **av, int ac);
int     ft_atoi(const char *nptr);


#endif