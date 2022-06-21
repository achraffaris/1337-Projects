#include "philo.h"

int main(int ac, char **av)
{
    simulation_t s;

    if (ac > 6)
        return (0);
    simulation_init(&s, av);
    int i = simulation_start(&s);
    return (i);
}