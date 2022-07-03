/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:46:36 by afaris            #+#    #+#             */
/*   Updated: 2022/07/03 11:25:26 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <semaphore.h>
#include <signal.h>
#include <fcntl.h> 
#include <sys/stat.h>

# define TRUE 1
# define FALSE 0
# define MICROSECOND 1000
# define MEALS_COMPLETED 15
# define DIED 4

typedef struct fork
{
    int id;
    sem_t *s_fork;
} fork_t;

typedef struct simulation
{
    int                 n_philos;
    int                 time_die;
    int                 time_eat;
    int                 time_sleep;
    int                 n_meals;
    fork_t              *forks;
    sem_t               *s_print;
    sem_t               *check_death;
    int                 n;
}   simulation_t;

typedef struct philo
{
    int                 id;
    pthread_t           thid;
    pid_t               pid;
    int                 n_meals;
    int                 eated_at;
    int                 started_at;
    int                 full;
    fork_t              left_fork;
    fork_t              right_fork;
    sem_t               *death_check;
    sem_t               *meals_check;
    simulation_t        *sim;
}   philo_t;

int                     ft_atoi(const char *nptr);
char                    *ft_strjoin(char *s1, char *s2);
char                    *ft_itoa(int n);
int                     current_time();
fork_t                  *new_forks(int n);
void                    print_record(char *record, philo_t *ph);
void                    eating(philo_t *ph);
void                    *checking(void *philos);

#endif

