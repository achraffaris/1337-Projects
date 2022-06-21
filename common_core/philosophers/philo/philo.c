/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:48:16 by afaris            #+#    #+#             */
/*   Updated: 2022/06/21 16:48:17 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    simulation_t s;

    if (ac > 6)
        return (0);
    simulation_init(&s, av);
    int i = simulation_start(&s);
    return (i);
}