#include "../philo.h"

fork_t  *create_forks(int philos)
{
    int i;

    i = 0;
    fork_t *forks;
    forks = malloc(sizeof(fork_t) * philos);
    while (i < philos)
    {
        pthread_mutex_init(&forks[i].mutex_fork, NULL);
        forks[i].status = 1;
        forks[i].id = i;
        i++;
    }
    return forks;
}

int     current_time_ms()
{
    int now_ms;
    struct timeval now;
    
    now_ms = 0;
    gettimeofday(&now, NULL);
    now_ms = (now.tv_sec * MICROSECOND) + (now.tv_usec / MICROSECOND);
    return (now_ms);
}
void    print_record(char *record, philo_t *ph)
{
    int start_ms;
    pthread_mutex_lock(&ph->s->mutex_print);
    start_ms = ph->sim_start_ms;
    printf("%dms %d %s\n", current_time_ms()-start_ms ,ph->id, record);
    pthread_mutex_unlock(&ph->s->mutex_print);
}

int     is_alive(philo_t *ph)
{
    int now_ms;
    
    now_ms = current_time_ms();
    pthread_mutex_lock(&ph->s->mutex_check);
    if (now_ms >= ph->eated_at + ph->s->die_time)
    {
        print_record("died", ph);
        pthread_mutex_lock(&ph->s->mutex_print);
        return (0);
    }
    pthread_mutex_unlock(&ph->s->mutex_check);
    return 1;
}

void    is_eating(philo_t *ph)
{
    ph->eated_at = current_time_ms();
    print_record("is eating", ph);
    usleep(ph->s->eat_time * MICROSECOND);
    if (ph->s->n_eat)
        ph->n_eat += 1;
    if (ph->n_eat >= ph->s->n_eat && !ph->completed)
    {
        ph->completed = TRUE;
        pthread_mutex_lock(&ph->s->mutex_check3);
        ph->s->n_philos_eated++;
        pthread_mutex_unlock(&ph->s->mutex_check3);
    }
    pthread_mutex_unlock(&ph->left_fork->mutex_fork);
    pthread_mutex_unlock(&ph->right_fork->mutex_fork);
}
