/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:48:10 by afaris            #+#    #+#             */
/*   Updated: 2022/06/27 15:25:45 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
    s->n_philos_eated = 0;
    pthread_mutex_init(&s->mtx_check_death, NULL);
    pthread_mutex_init(&s->mtx_check_optional, NULL);
    pthread_mutex_init(&s->mtx_print, NULL);
}

void    *simulation(void *philos)
{
    philo_t *ph = (philo_t *)philos;
    pthread_mutex_lock(&ph->mtx_check_death);
    ph->eated_at = current_time_ms();
    pthread_mutex_unlock(&ph->mtx_check_death);
    ph->sim_start_ms = current_time_ms();
    while (1337)
    {
        if ((ph->id) % 2 == 0)
            usleep(100);
        pthread_mutex_lock(&ph->left_fork->mutex_fork);
        print_record("has taken a fork", ph);
        pthread_mutex_lock(&ph->right_fork->mutex_fork);
        print_record("has taken a fork", ph);
        is_eating(ph);
        print_record("is sleeping", ph);
        usleep(ph->s->sleep_time  * MICROSECOND);
        print_record("is thinking", ph);
    }
    return (0);
}

int    simulation_check(philo_t *ph)
{
    int i;

    i = 0;
    while (TRUE)
    {
        usleep(100);
        if (!is_alive(&ph[i]))
            return (TRUE);
        pthread_mutex_lock(&ph->s->mtx_check_optional);
        if (ph->s->n_philos_eated == ph->s->n_philos)
            return (TRUE);
        pthread_mutex_unlock(&ph->s->mtx_check_optional);
        i++;
        if (i == ph->s->n_philos)
            i = 0;
    }
    return (TRUE);
}

int simulation_end(simulation_t *s, philo_t *ph)
{
    simulation_check(ph);
    free(ph);
    free(s->forks);
    return (TRUE);
}

int    simulation_start(simulation_t *s)
{
    int i;
    philo_t *ph;

    ph = malloc(sizeof(philo_t) * s->n_philos);
    i = 0;
    while (i < s->n_philos)
    {
        ph[i].id = i + 1;
        ph[i].s = s;
        ph[i].n_eat = 0;
        ph[i].left_fork = &s->forks[i];
        if (i == s->n_philos - 1)
            ph[i].right_fork = ph[0].left_fork;
        else
            ph[i].right_fork = &s->forks[i + 1];
        pthread_mutex_init(&ph[i].mtx_check_death, NULL);
        pthread_create(&ph[i].th_id, NULL, &simulation, &ph[i]);
        i++;
    }
    return (simulation_end(s, ph));
}
