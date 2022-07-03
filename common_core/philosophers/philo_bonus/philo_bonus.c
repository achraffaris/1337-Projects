/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:20:07 by afaris            #+#    #+#             */
/*   Updated: 2022/07/03 13:37:56 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	simulation_init(t_simulation *s, char **av)
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

void	simulation_end(t_simulation *s, t_philo *ph)
{
	int	i;

	i = 0;
	if (signal_received(s))
	{
		while (i < s->n_philos)
		{
			sem_close(s->forks[i].s_fork);
			kill(ph[i].pid, SIGTERM);
			i++;
		}
		exit(EXIT_SUCCESS);
	}
}

void	simulation(t_philo *ph)
{
	pthread_create(&ph->thid, 0, &checking, ph);
	ph->started_at = current_time();
	while (1337)
	{
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

void	simulation_start(t_simulation s)
{
	int		i;
	t_philo	*ph;

	i = 0;
	ph = malloc(sizeof(t_philo) * s.n_philos);
	if (!ph)
		exit(EXIT_FAILURE);
	while (i < s.n_philos)
	{
		philo_init(&ph[i], &s, i);
		ph[i].pid = fork();
		if (ph[i].pid == 0)
			simulation(&ph[i]);
		else
			i++;
	}
	simulation_end(&s, ph);
}

int	main(int ac, char **av)
{
	t_simulation	s;

	if (!(ac >= 5 && ac <= 6))
		return (0);
	simulation_init(&s, av);
	simulation_start(s);
	return (0);
}
