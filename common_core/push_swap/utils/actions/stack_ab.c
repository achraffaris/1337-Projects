#include "../../push_swap.h"

void    swap_ab(t_stack a, t_stack b)
{
    swap_a(a);
    swap_b(b);
    write(1, "ss\n", 3);
    
}
void    rotate_ab(t_stack a, t_stack b)
{
    rotate_a(a);
    rotate_b(b);
    write(1, "rr\n", 3);
}
void    rev_rotate_ab(t_stack a, t_stack b)
{
    rev_rotate_a(a);
    rev_rotate_b(b);
    write(1, "rrr\n", 4);
}