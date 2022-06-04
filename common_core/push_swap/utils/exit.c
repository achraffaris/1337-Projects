#include "../push_swap.h"

void    raise_error()
{
    write(2, "Error\n", 7);
    exit(1);
}

void    ft_exit(t_stack a)
{
    if (a.arr)
        free(a.arr);
    raise_error();
}