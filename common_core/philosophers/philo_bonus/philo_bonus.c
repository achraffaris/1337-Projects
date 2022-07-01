/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:20:07 by afaris            #+#    #+#             */
/*   Updated: 2022/07/01 18:28:30 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// ./philo 5 800 200 200 7

void    simulation_end(simulation_t *s, philo_t *ph)
{
    int i;

    i = 0;
    waitpid(0, 0, 0);
    sem_wait(s->s_print);
    while (i < s->n_philos)
    {
        sem_close(s->forks[i].s_fork);
        kill(ph[i].pid, SIGTERM);
        i++;
    }
    exit(EXIT_SUCCESS);
}

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
    sem_post(ph->death_check);
    print_record("is eating", ph);
    usleep(ph->sim->time_eat * MICROSECOND);
    sem_post(ph->left_fork.s_fork);
    sem_post(ph->right_fork.s_fork);
}

void    *checking(void *philos)
{
    philo_t *ph;

    ph = (philo_t *)philos;
    while (1337)
    {
        sem_wait(ph->death_check);
        if (ph->eated_at && (current_time() >= ph->eated_at + ph->sim->time_die))
        {
            print_record("died", ph);
            exit(EXIT_SUCCESS);
        }
        sem_post(ph->death_check);
    }
    return (NULL);
}

void    simulation_init(simulation_t *s, char **av)
{
    s->n_philos = ft_atoi(av[1]);
    s->time_die = ft_atoi(av[2]);
    s->time_eat = ft_atoi(av[3]);
    s->time_sleep = ft_atoi(av[4]);
    s->n_meals = 0;
    sem_unlink("s_print");
    s->s_print = sem_open("s_print", O_CREAT | O_RDWR, 0777, 1);
    if (av[5])
        s->n_meals = ft_atoi(av[5]);
    s->forks = new_forks(s->n_philos);
}

void    simulation(philo_t *ph)
{
    ph->started_at = current_time();
    pthread_create(&ph->thid, 0, &checking, ph);
    while (1337)
    {
        if (ph->id % 2 == 0)
            usleep(150);
        sem_wait(ph->left_fork.s_fork);
        print_record("taken a fork", ph);
        sem_wait(ph->right_fork.s_fork);
        print_record("taken a fork", ph);
        eating(ph);
        print_record("is sleeping", ph);
        usleep(ph->sim->time_sleep * MICROSECOND);
        print_record("is thinking", ph);
    }
}

void    simulation_start(simulation_t s)
{
    int i;
    philo_t *ph;

    i = 0;
    ph = malloc(sizeof(philo_t) * s.n_philos);
    if (!ph)
        exit(EXIT_FAILURE);
    while (i < s.n_philos)
    {
        ph[i].id = i + 1;
        ph[i].n_meals = 0;
        ph[i].sim = &s;
        ph[i].eated_at = 0;
        ph[i].left_fork = s.forks[i];
        sem_unlink("death_check");
        ph[i].death_check = sem_open("death_check", O_CREAT | O_RDWR, 0777, 1);
        if (i == s.n_philos - 1)
            ph[i].right_fork = s.forks[0];
        else
            ph[i].right_fork = s.forks[i + 1];
        ph[i].pid = fork();
        if (ph[i].pid == 0)
            simulation(&ph[i]);
        else
            i++;
    }
    simulation_end(&s, ph);
}

int main(int ac, char **av)
{
    simulation_t s;
    
    if (!(ac >= 5 && ac <= 6))
        return (0);
    simulation_init(&s, av);
    simulation_start(s);
    return (0);
}