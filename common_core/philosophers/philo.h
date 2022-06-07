/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gitpod <gitpod@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:09:28 by afaris            #+#    #+#             */
/*   Updated: 2022/06/07 18:41:10 by gitpod           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct simulation
{
    int n_philos;
    int sleep_time;
    int eat_time;
    int die_time;
    int n_eat;
    pthread_mutex_t *forks;
    pthread_mutex_t mutex;
    int thread_ready;
} simulation_t;


typedef struct philo
{
    int id;
    pthread_t th_id;
    simulation_t *s;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
} philo_t;


int	ft_atoi(const char *nptr);

#endif