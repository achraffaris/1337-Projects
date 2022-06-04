/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitpod <gitpod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:47:50 by afaris            #+#    #+#             */
/*   Updated: 2022/05/27 08:46:36 by gitpod           ###   ########.fr       */
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
    int top;
    int *arr;
}   t_stack;

int     ft_strcmp(const char *s1, const char *s2);
void    raise_error();
t_stack clean_data(char **av, int ac);
int     ft_atoi(const char *nptr);
int     is_number(char c);
int     is_sign(char c);
int	    ft_strlen(char *str);
void    ft_exit(t_stack a);
int     is_max(t_stack s, int n);
int     is_min(t_stack s, int n);
int     is_sorted(t_stack s);
void    swap(int *a, int *b);
void    swap_a(t_stack a);
void    swap_b(t_stack a);
void    rotate_a(t_stack a);
void    rotate_b(t_stack b);
void    rev_rotate_a(t_stack a);
void    rev_rotate_b(t_stack b);
void    add_element(t_stack *a, int n);
void    remove_element(t_stack *b);
void    push_a(t_stack *a, t_stack *b);
void    push_b(t_stack *a, t_stack *b);
void    rev_rotate_ab(t_stack a, t_stack b);
void    rotate_ab(t_stack a, t_stack b);
void    swap_ab(t_stack a, t_stack b);




#endif