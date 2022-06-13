/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:45:50 by gitpod            #+#    #+#             */
/*   Updated: 2022/06/13 16:01:14 by afaris           ###   ########.fr       */
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

int current_time_ms()
{
    int now_ms;
    struct timeval now;
    
    now_ms = 0;
    gettimeofday(&now, NULL);
    now_ms = (now.tv_sec * MICROSECOND) + (now.tv_usec / MICROSECOND);
    return (now_ms);
}
void    print_record(char *record, philo_t *ph)
{
    int start_ms;
    pthread_mutex_lock(&ph->s->mutex_print);
    start_ms = ph->sim_start_ms;
    printf("%dms %d %s\n", current_time_ms()-start_ms ,ph->id, record);
    pthread_mutex_unlock(&ph->s->mutex_print);
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
    pthread_mutex_init(&s->mutex_check, NULL);
    pthread_mutex_init(&s->mutex_check2, NULL);
    s->all_alive = TRUE;
}

int is_alive(philo_t *ph)
{
    int now_ms;
    
    now_ms = current_time_ms();
    pthread_mutex_lock(&ph->s->mutex_check);
    if (now_ms >= ph->eated_at + ph->s->die_time)
    {
        ph->s->all_alive = FALSE;
        print_record("died", ph);
        pthread_mutex_lock(&ph->s->mutex_print);
        return (0);
    }
    pthread_mutex_unlock(&ph->s->mutex_check);
    return 1;
}

void    is_eating(philo_t *ph)
{
    ph->eated_at = current_time_ms();
    print_record("is eating", ph);
    usleep(ph->s->eat_time * MICROSECOND);
    ph->n_eat += 1;
    if (ph->n_eat >= ph->s->n_eat)
        ph->completed = TRUE;
    pthread_mutex_unlock(&ph->left_fork->mutex_fork);
    pthread_mutex_unlock(&ph->right_fork->mutex_fork);
}

int    all_alive(simulation_t *s)
{
    pthread_mutex_lock(&s->mutex_check2);
    if (!s->all_alive)
        return (0);
    pthread_mutex_unlock(&s->mutex_check2);
    return (1);
}  

void    *simulation(void *philos)
{
    philo_t *ph = (philo_t *)philos;
    ph->eated_at = current_time_ms();
    ph->sim_start_ms = current_time_ms();
    while (1337)
    {
        if ((ph->id + 1) % 2 == 0)
            usleep(50);
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

int all_full(simulation_t *s)
{
    int i;

    i = 0;
    int k;

    k = 1;
    philo_t *ph = (philo_t *)s->ph;
    while(i < s->n_philos)
    {
        if (ph[i].completed)
            k++;
        i++;
    }
    if (k == s->n_eat)
        return (1);
    return (0);
    
}

int    philos_init(simulation_t *s)
{
    int i;
    philo_t *ph;

    ph = malloc(sizeof(philo_t) * s->n_philos);
    i = 0;
    while (i < s->n_philos)
    {
        ph[i].id = i;
        ph[i].s = s;
        ph[i].n_eat = 0;
        ph[i].left_fork = &s->forks[i];
        if (i == s->n_philos - 1)
            ph[i].right_fork = ph[0].left_fork;
        else
            ph[i].right_fork = &s->forks[i + 1];
        pthread_create(&ph[i].th_id, NULL, &simulation, &ph[i]);
        i++;
    }
    s->ph = ph;
    i = 0;
    while (1337)
    {
        usleep(50);
        if (!is_alive(&ph[i]) || all_full(s))
            return (0);
        i++;
        if (i == s->n_philos)
            i = 0;
    }
    return (1);
}

int main(int ac, char **av)
{
    simulation_t s;

    if (ac == 7)
        return (0);
    simulation_init(&s, av);
    if (!philos_init(&s))
        return (0);
    return(0);
}