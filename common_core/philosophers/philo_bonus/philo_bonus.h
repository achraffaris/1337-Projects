/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:46:36 by afaris            #+#    #+#             */
/*   Updated: 2022/06/27 15:57:40 by afaris           ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0
# define MICROSECOND 1000

typedef struct fork
{
    int id;
    sem_t s_fork;
} fork_t;

typedef struct simulation
{
    int     n_philos;
    int     time_die;
    int     time_eat;
    int     time_sleep;
    int     n_meals;
    fork_t  *forks;
    sem_t   s_print;
} simulation_t;

typedef struct philo
{
    int             id;
    pthread_t       thid;
    pid_t           pid;
    int             n_meals;
    int             eated_at;
    int             started_at;
    fork_t          *left_fork;
    fork_t          *right_fork;
    sem_t           death_check;
    simulation_t    *sim;
} philo_t;

int     ft_atoi(const char *nptr);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(int n);


#endif

