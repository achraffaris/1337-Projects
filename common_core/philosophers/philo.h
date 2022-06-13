/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:09:28 by afaris            #+#    #+#             */
/*   Updated: 2022/06/13 15:32:38 by afaris           ###   ########.fr       */
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
#define TRUE 1
#define FALSE 0
#define MICROSECOND 1000
#define ALIVE 1

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
    pthread_mutex_t mutex_check;
    pthread_mutex_t mutex_check2;
    int all_alive;
    void *ph;
    pthread_t tmp;
} simulation_t;

typedef struct philo
{
    int id;
    pthread_t th_id;
    simulation_t *s;
    fork_t *left_fork;
    fork_t *right_fork;
    struct timeval sim_time;
    struct timeval current_time;
    int sim_start_ms;
    int eated_at;
    int n_eat;
    int completed;
    int status;
} philo_t;


int	ft_atoi(const char *nptr);

#endif