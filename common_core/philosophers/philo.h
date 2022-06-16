/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 10:09:28 by afaris            #+#    #+#             */
/*   Updated: 2022/06/16 09:13:31 by afaris           ###   ########.fr       */
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
    pthread_mutex_t mtx_print;
    pthread_mutex_t mtx_check_death;
    pthread_mutex_t mtx_check_optional;
    int all_alive;
    int n_philos_eated;
} simulation_t;

typedef struct philo
{
    int id;
    pthread_t th_id;
    simulation_t *s;
    fork_t *left_fork;
    fork_t *right_fork;
    struct timeval sim_time;
    int sim_start_ms;
    int eated_at;
    int n_eat;
    int completed;
    int status;
} philo_t;


int     ft_atoi(const char *nptr);
void    simulation_init(simulation_t *s, char **av);
void    simulation_init(simulation_t *s, char **av);
void    *simulation(void *philos);
int    simulation_check(philo_t *ph);
int     simulation_start(simulation_t *s);
fork_t  *create_forks(int philos);
int     current_time_ms();
void    print_record(char *record, philo_t *ph);
int     is_alive(philo_t *ph);
void    is_eating(philo_t *ph);

#endif