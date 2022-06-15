#include "../philo.h"

void    simulation_init(simulation_t *s, char **av)
{
    s->n_philos = ft_atoi(av[1]);
    s->die_time = ft_atoi(av[2]);
    s->eat_time = ft_atoi(av[3]);
    s->sleep_time = ft_atoi(av[4]);
    s->n_eat = 0;
    if (av[5])
        s->n_eat = ft_atoi(av[5]);
    s->forks = create_forks(s->n_philos);
    s->n_philos_eated = 0;
    pthread_mutex_init(&s->mutex_print, NULL);
    pthread_mutex_init(&s->mutex_check, NULL);
    pthread_mutex_init(&s->mutex_check2, NULL);
    pthread_mutex_init(&s->mutex_check3, NULL);
    s->all_alive = TRUE;
}

void    *simulation(void *philos)
{
    philo_t *ph = (philo_t *)philos;
    ph->eated_at = current_time_ms();
    ph->sim_start_ms = current_time_ms();
    while (1337)
    {
        if ((ph->id + 1) % 2 == 0)
            usleep(50);
        pthread_mutex_lock(&ph->left_fork->mutex_fork);
        print_record("has taken a fork", ph);
        pthread_mutex_lock(&ph->right_fork->mutex_fork);
        print_record("has taken a fork", ph);
        is_eating(ph);
        print_record("is sleeping", ph);
        usleep(ph->s->sleep_time  * MICROSECOND);
        print_record("is thinking", ph);
    }
    return (0);
}

void    simulation_check(philo_t *ph)
{
    int i;
    int up;

    i = 0;
    up = TRUE;
    while (up)
    {
        usleep(50);
        if (!is_alive(&ph[i]))
            up = FALSE;
        pthread_mutex_lock(&ph->s->mutex_check3);
        if (ph->s->n_philos_eated == ph->s->n_philos)
            up = FALSE;
        pthread_mutex_unlock(&ph->s->mutex_check3);
        i++;
        if (i == ph->s->n_philos)
            i = 0;
    }
}

int    simulation_start(simulation_t *s)
{
    int i;
    philo_t *ph;

    ph = malloc(sizeof(philo_t) * s->n_philos);
    i = 0;
    while (i < s->n_philos)
    {
        ph[i].id = i;
        ph[i].s = s;
        ph[i].n_eat = 0;
        ph[i].completed = FALSE;
        ph[i].left_fork = &s->forks[i];
        if (i == s->n_philos - 1)
            ph[i].right_fork = ph[0].left_fork;
        else
            ph[i].right_fork = &s->forks[i + 1];
        pthread_create(&ph[i].th_id, NULL, &simulation, &ph[i]);
        i++;
    }
    simulation_check(ph);
    return (1);
}
