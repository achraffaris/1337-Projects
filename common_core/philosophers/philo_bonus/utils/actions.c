/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:30:58 by afaris            #+#    #+#             */
/*   Updated: 2022/07/03 12:11:02 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int current_time()
{
    int now_ms;
    struct timeval now;
    
    now_ms = 0;
    gettimeofday(&now, NULL);
    now_ms = (now.tv_sec * MICROSECOND) + (now.tv_usec / MICROSECOND);
    return (now_ms);
}

fork_t  *new_forks(int n)
{
    int i;
    fork_t  *forks;
    
    i = 0;
    forks = malloc(sizeof(fork_t) * n);
    if (!forks)
        exit(EXIT_FAILURE);
    while (i < n)
    {
        forks[i].id = i + 1;
        sem_unlink(ft_strjoin("fork_", ft_itoa(i + 1)));
        forks[i].s_fork = sem_open(ft_strjoin("fork_", ft_itoa(i + 1)), O_CREAT | O_RDWR, 0777, 1);
        i++;
    }
    return (forks);
}

void    print_record(char *record, philo_t *ph)
{   
    sem_wait(ph->sim->s_print);
    printf("%dms %d %s\n", current_time() - ph->started_at ,ph->id, record);
    sem_post(ph->sim->s_print);
}

void    eating(philo_t *ph)
{
    sem_wait(ph->death_check);
    ph->eated_at = current_time();
    print_record("is eating", ph);
    usleep(ph->sim->time_eat * MICROSECOND);
    ph->n_meals++;
    sem_post(ph->death_check);
    sem_post(ph->left_fork.s_fork);
    sem_post(ph->right_fork.s_fork);
}

void    *checking(void *philos)
{
    philo_t *ph;

    ph = (philo_t *)philos;
    while (1337)
    {
        usleep(150);
        sem_wait(ph->death_check);
        if (ph->eated_at && (current_time() >= ph->eated_at + ph->sim->time_die))
        {
            print_record("died", ph);
            exit(EXIT_FAILURE);
        }
        else if (!ph->full && ph->sim->n_meals && ph->n_meals >= ph->sim->n_meals)
        {
            print_record("full", ph);
            ph->full = TRUE;
            exit(EXIT_SUCCESS);
        }
        sem_post(ph->death_check);
    }
    return (NULL);
}
