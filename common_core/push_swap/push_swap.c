/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitpod <gitpod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:47:33 by afaris            #+#    #+#             */
/*   Updated: 2022/05/27 08:30:44 by gitpod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void    print_stack(t_stack s, char *title)
{
    int i;

    i = s.size - 1;
    printf("-------- %s --------\n", title);
    while (i >= 0)
    {
        printf("s[%d] = %d\n",i, s.arr[i]);
        i--;
    }
}

int main(int ac, char **av)
{
    t_stack a;
    t_stack b;
    a = clean_data(av, ac);
    b = clean_data(av, ac);
    print_stack(a, "Innit [stack a]");
    print_stack(b, "Innit [stack b]");
    push_b(&a, &b);
    print_stack(a, "push_b [stack a]");
    print_stack(b, "push_b [stack b]");
    free(a.arr);
}