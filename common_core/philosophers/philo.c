/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitpod <gitpod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:45:50 by gitpod            #+#    #+#             */
/*   Updated: 2022/06/07 18:25:45 by gitpod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// ./philo 7 800 200 200 5

pthread_mutex_t *create_forks(int philos)
{
    int i;

    i = 0;
    pthread_mutex_t *pth_mtx;
    pth_mtx = malloc(sizeof(pthread_mutex_t) * philos);
    while (i < philos)
    {
        pthread_mutex_init(&pth_mtx[i], NULL);
        i++;
    }
    return pth_mtx;
}

void    simulation_init(simulation_t *s, char **av)
{
    s->n_philos = ft_atoi(av[1]);
    s->die_time = ft_atoi(av[2]);
    s->eat_time = ft_atoi(av[3]);
    s->sleep_time = ft_atoi(av[4]);
    s->n_eat = 0;
    if (av[5])
        s->n_eat = ft_atoi(av[5]);
    s->forks = create_forks(s->n_philos);
}

void    *simulation(void *philos)
{
    philo_t *ph = (philo_t *)philos;
    printf("Hi Iam philo no.%d\n", ph->id);

    return (0);
}

void    philos_init(philo_t *ph, simulation_t *s)
{
    int i;

    i = 0;
    while (i < s->n_philos)
    {
        ph[i].id = i;
        ph[i].s = s;
        ph[i].left_fork = s->forks[i];
        if (i == s->n_philos - 1)
            ph[i].right_fork = s->forks[0];
        else
            ph[i].right_fork = s->forks[i + 1];
        pthread_create(&ph[i].th_id, NULL, &simulation, &ph[i]);
        i++;
    }
    
}

void    wait_threads(philo_t *ph)
{
    int i;

    i = 0;
    while (i < ph->s->n_philos)
    {
        pthread_join(ph->th_id, NULL);
        i++;
    }
}
int main(int ac, char **av)
{
    simulation_t s;
    philo_t *ph;

    if (ac == 7)
        return (0);
    simulation_init(&s, av);
    ph = malloc(sizeof(philo_t) * s.n_philos);
    philos_init(ph, &s);
    wait_threads(ph);
    
}