/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:20:07 by afaris            #+#    #+#             */
/*   Updated: 2022/06/27 16:01:02 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// ./philo 5 800 200 200 7

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
        sem_open(ft_strjoin("s_fork_", ft_itoa(i + 1)), O_CREAT);
        i++;
    }
    return (forks);
}

void    simulation_init(simulation_t *s)
{
    s->n_philos = ft_atoi(av[1]);
    s->time_die = ft_atoi(av[2]);
    s->time_eat = ft_atoi(av[3]);
    s->time_sleep = ft_atoi(av[4]);
    s->n_meals = 0;
    if (av[5])
        s->n_meals = ft_atoi(av[5]);
    s->forks = new_forks(s->n_philos);
}

void    simulation_start(simulation_t s)
{
    int i;
    philo_t *ph;

    ph = malloc(sizeof(philo_t) * s.n_philos);
    if (!ph)
        exit(EXIT_FAILURE);
    while (i < s.n_philos)
    {
        ph[i].id = i + 1;
        ph[i].n_meals = 0;
        ph[i].sim = s;
        ph[i].left_fork = s.forks[i];
        if (i == s.n_philos - 1)
            ph[i].right_fork = s.forks[0];
        else
            ph[i].right_fork = s.forks[i + 1];
    }
    
    i = 0;
    
}

int main(int ac, char **av)
{
    simulation_t s;
    
    if (!(ac >= 5 && ac <= 6))
        return (0);
    simulation_init(&s);
    simulation_start(s);
    return (0);
}