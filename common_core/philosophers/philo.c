/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitpod <gitpod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:45:50 by gitpod            #+#    #+#             */
/*   Updated: 2022/06/09 19:07:18 by gitpod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// ./philo 7 800 200 200 5

fork_t *create_forks(int philos)
{
    int i;

    i = 0;
    fork_t *forks;
    forks = malloc(sizeof(fork_t) * philos);
    while (i < philos)
    {
        pthread_mutex_init(&forks[i].mutex_fork, NULL);
        forks[i].status = 1;
        forks[i].id = i;
        i++;
    }
    return forks;
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
    pthread_mutex_init(&s->mutex_print, NULL);
    s->all_alive = TRUE;
}

void is_alive(philo_t *ph)
{
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    if (current_time.tv_usec > ph->expected_to_die.tv_usec)
    {
        printf("%d died\n", ph->id);
        ph->s->all_alive = FALSE;
    }
}
void    *simulation(void *philos)
{
    philo_t *ph = (philo_t *)philos;
    gettimeofday(&ph->current_time, NULL);
    ph->expected_to_die.tv_usec = ph->current_time.tv_usec + (ph->s->die_time * MICROSECOND);
    while (1337 && ph->s->all_alive)
    {
        is_alive(ph);
        if (ph->left_fork->status == AVAILABLE && ph->right_fork->status == AVAILABLE)
        {
            pthread_mutex_lock(&ph->left_fork->mutex_fork);
            ph->left_fork->status = UNAVAILABLE;
            printf("%d has taken a fork\n", ph->id);
            pthread_mutex_lock(&ph->right_fork->mutex_fork);
            ph->right_fork->status = UNAVAILABLE;
            printf("%d has taken a fork\n", ph->id);
            ph->status = IS_EATING;
            gettimeofday(&ph->current_time, NULL);
            ph->expected_to_die.tv_usec = ph->current_time.tv_usec + (ph->s->die_time * MICROSECOND);
            printf("%d is eating\n", ph->id);
            usleep(ph->s->eat_time * MICROSECOND);
            ph->left_fork->status = AVAILABLE;
            ph->right_fork->status = AVAILABLE;
            pthread_mutex_unlock(&ph->left_fork->mutex_fork);
            pthread_mutex_unlock(&ph->right_fork->mutex_fork);
            printf("%d is sleeping\n", ph->id);
            usleep(ph->s->sleep_time  * MICROSECOND);
            printf("%d is thinking ...\n", ph->id);
        }
    }
    return (0);
}

philo_t    *philos_init(simulation_t *s)
{
    int i;
    philo_t *ph;

    ph = malloc(sizeof(philo_t) * s->n_philos);
    i = 0;
    while (i < s->n_philos)
    {
        ph[i].id = i;
        ph[i].s = s;
        ph[i].left_fork = &s->forks[i];
        if (i == s->n_philos - 1)
            ph[i].right_fork = ph[0].left_fork;
        else
            ph[i].right_fork = &s->forks[i + 1];
        pthread_create(&ph[i].th_id, NULL, &simulation, &ph[i]);
        i++;
    }
    return (ph);
}

void    wait_threads(philo_t *ph)
{
    int i;

    i = 0;
    while (i < ph->s->n_philos)
    {
        pthread_join(ph[i].th_id, NULL);
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
    ph = philos_init(&s);
    wait_threads(ph);
    
    
    
}