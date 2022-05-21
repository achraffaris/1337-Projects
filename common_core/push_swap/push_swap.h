/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:47:50 by afaris            #+#    #+#             */
/*   Updated: 2022/05/11 16:14:23 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define INT_MIN 2147483648

#include <stdlib.h>
#include <unistd.h>

typedef struct stack
{
    int size;
    int *arr;
} t_stack;

int     ft_strcmp(const char *s1, const char *s2);
void    raise_error();
t_stack clean_data(char **av, int ac);
int     ft_atoi(const char *nptr);
int is_number(char c);
int is_sign(char c);



#endif