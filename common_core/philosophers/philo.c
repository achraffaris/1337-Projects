#include "philo.h"

int main(int ac, char **av)
{
    simulation_t s;

    if (ac == 7)
        return (0);
    simulation_init(&s, av);
    return (simulation_start(&s));
}