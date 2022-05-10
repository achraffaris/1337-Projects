/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:47:33 by afaris            #+#    #+#             */
/*   Updated: 2022/05/10 13:48:38 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int main(int ac, char **av)
{
    int *n;
    int i;

    i = 0;
    n = clean_data(av, ac);
    while (i < ac - 1)
    {
        printf("n[%d] = %d \n", i, n[i]);
        i++;
    }
}