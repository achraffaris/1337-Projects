/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:20:07 by afaris            #+#    #+#             */
/*   Updated: 2022/07/03 12:15:15 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    simulation_init(simulation_t *s, char **av)
{
    s->n_philos = ft_atoi(av[1]);
    s->time_die = ft_atoi(av[2]);
    s->time_eat = ft_atoi(av[3]);
    s->time_sleep = ft_atoi(av[4]);
    sem_unlink("check_death");
    s->check_death = sem_open("check_death", O_CREAT | O_RDWR, 0777, 1);
    s->n_meals = 0;
    if (av[5])
        s->n_meals = ft_atoi(av[5]);
    sem_unlink("s_print");
    s->s_print = sem_open("s_print", O_CREAT | O_RDWR, 0777, 1);
    s->forks = new_forks(s->n_philos);
    s->n = 0;
}

int     signal_received(simulation_t *s)
{
    int i;
    int status;
    
    i = 0;
    while (1337)
    {   
        waitpid(0, &status, 0);
        if (status == EXIT_FAILURE || (i == s->n_philos))
        {
            printf("program will stop now i = %d and it should be %d\n", i, s->n_philos);
            break ;
        } 
        else if (status == EXIT_SUCCESS)
            i++;
        printf("(%d / %d) are full\n", i, s->n_philos);
    }
    return (TRUE);
}

void    simulation_end(simulation_t *s, philo_t *ph)
{
    int i;
    
    i = 0;
    if (signal_received(s))
    {
        sem_wait(s->s_print);
        while (i < s->n_philos)
        {
            sem_close(s->forks[i].s_fork);
            kill(ph[i].pid, SIGTERM);
            i++;
        }
        exit(EXIT_SUCCESS);
    }
}

void    simulation(philo_t *ph)
{
    pthread_create(&ph->thid, 0, &checking, ph);
    ph->started_at = current_time();
    while (1337)
    {
        print_record("still running", ph);
        if (ph->id % 2 == 0)
            usleep(50);
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
        ph[i].full = FALSE;
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