/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:47:33 by afaris            #+#    #+#             */
/*   Updated: 2022/05/11 16:27:01 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int main(int ac, char **av)
{
    t_stack a;
    int i;

    
    a = clean_data(av, ac);
    i = a.size - 1;
    while (i >= 0)
    {
        printf("a[%d] = %d\n",i, a.arr[i]);
        i--;
    }
}