/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitpod <gitpod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:09:28 by afaris            #+#    #+#             */
/*   Updated: 2022/06/09 20:14:31 by gitpod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>


#define AVAILABLE 1
#define UNAVAILABLE 0
#define IS_SLEEPING 2
#define IS_EATING 3
#define IS_THIKING 4
#define TRUE 1
#define FALSE 0
#define MICROSECOND 1000

typedef struct fork
{
    int id;
    pthread_mutex_t mutex_fork;
    int status;
} fork_t;

typedef struct simulation
{
    int n_philos;
    int sleep_time;
    int eat_time;
    int die_time;
    int n_eat;
    fork_t *forks;
    pthread_mutex_t mutex_print;
    int all_alive;
} simulation_t;


typedef struct philo
{
    int id;
    pthread_t th_id;
    simulation_t *s;
    fork_t *left_fork;
    fork_t *right_fork;
    struct timeval current_time;
    struct timeval sim_time;
    int status;
    struct timeval tmp;
    int expected_to_die;
} philo_t;

int	ft_atoi(const char *nptr);

#endif