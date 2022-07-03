/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaris <afaris@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 12:37:44 by afaris            #+#    #+#             */
/*   Updated: 2022/07/03 13:28:21 by afaris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	signal_received(t_simulation *s)
{
	int	i;
	int	status;

	i = 0;
	while (1337)
	{
		waitpid(0, &status, 0);
		if (status != EXIT_SUCCESS || (i == s->n_philos))
			break ;
		else if (status == EXIT_SUCCESS)
			i++;
	}
	return (TRUE);
}

void	philo_init(t_philo *ph, t_simulation *s, int i)
{
	ph->id = i + 1;
	ph->n_meals = 0;
	ph->sim = s;
	ph->eated_at = 0;
	ph->left_fork = s->forks[i];
	ph->full = FALSE;
	sem_unlink("death_check");
	ph->death_check = sem_open("death_check", O_CREAT | O_RDWR, 0777, 1);
	if (i == s->n_philos - 1)
		ph->right_fork = s->forks[0];
	else
		ph->right_fork = s->forks[i + 1];
}
