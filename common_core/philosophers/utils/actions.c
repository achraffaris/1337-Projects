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
    pthread_mutex_lock(&ph->s->mtx_print);
    start_ms = ph->sim_start_ms;
    printf("%dms %d %s\n", current_time_ms()-start_ms ,ph->id, record);
    pthread_mutex_unlock(&ph->s->mtx_print);
}

int     is_alive(philo_t *ph)
{
    pthread_mutex_lock(&ph->mtx_check_death);
    if (current_time_ms() >= (ph->eated_at + ph->s->die_time))
    {
        print_record("died", ph);
        pthread_mutex_lock(&ph->s->mtx_print);
        return (0);
    }
    pthread_mutex_unlock(&ph->mtx_check_death);
    return (1);
}

void    is_eating(philo_t *ph)
{
    print_record("is eating", ph);
    pthread_mutex_lock(&ph->mtx_check_death);
    ph->eated_at = current_time_ms();
    pthread_mutex_unlock(&ph->mtx_check_death);
    usleep(ph->s->eat_time * MICROSECOND);
    if (ph->s->n_eat)
    {
        ph->n_eat++;
        if (ph->n_eat >= ph->s->n_eat && !ph->completed)
        {
            ph->completed = TRUE;
            pthread_mutex_lock(&ph->s->mtx_check_optional);
            ph->s->n_philos_eated++;
            pthread_mutex_unlock(&ph->s->mtx_check_optional);
        }
    }
    pthread_mutex_unlock(&ph->left_fork->mutex_fork);
    pthread_mutex_unlock(&ph->right_fork->mutex_fork);
}
