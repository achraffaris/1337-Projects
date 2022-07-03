/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:46:36 by afaris            #+#    #+#             */
/*   Updated: 2022/07/03 12:52:08 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>
# include <fcntl.h> 
# include <sys/stat.h>

# define TRUE 1
# define FALSE 0
# define MICROSECOND 1000
# define MEALS_COMPLETED 15
# define DIED 4

typedef struct fork
{
	int					id;
	sem_t				*s_fork;
}	t_fork;

typedef struct simulation
{
	int					n_philos;
	int					time_die;
	int					time_eat;
	int					time_sleep;
	int					n_meals;
	t_fork				*forks;
	sem_t				*s_print;
	sem_t				*check_death;
	int					n;
}	t_simulation;

typedef struct philo
{
	int					id;
	pthread_t			thid;
	pid_t				pid;
	int					n_meals;
	int					eated_at;
	int					started_at;
	int					full;
	t_fork				left_fork;
	t_fork				right_fork;
	sem_t				*death_check;
	sem_t				*meals_check;
	t_simulation		*sim;
}	t_philo;

int						ft_atoi(const char *nptr);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_itoa(int n);
int						current_time(void);
t_fork					*new_forks(int n);
void					print_record(char *record, t_philo *ph);
void					eating(t_philo *ph);
void					*checking(void *philos);
int						signal_received(t_simulation *s);
void					philo_init(t_philo *ph, t_simulation *s, int i);

#endif